#include<exception>

#include"../../include/solver/gbf-solver.hpp"

GBFSolver::GBFSolver(IHeuristic* heuristic) {
  this->heuristic = heuristic;
}

GBFSolver::~GBFSolver() {
  delete this->heuristic;
}

gbf_node_pair_t GBFSolver::get_node_pair(SolverNode* node) {
  return std::make_pair(-this->heuristic->get_value(node->puzzle), node);
}

void GBFSolver::insert(EightPuzzle& puzzle, SolverNode* parent) {
  SolverNode* new_node = create_solver_node(puzzle, parent);
  this->queue.push(get_node_pair(new_node));
  this->nodes.push_back(new_node);
  this->visited[puzzle.get_id()] = new_node->moves;
}

SolverNode* GBFSolver::get_next() {
  auto [_, node] = queue.top();
  queue.pop();
  return node;
}

bool GBFSolver::is_visited(EightPuzzle& puzzle) {
  return visited.find(puzzle.get_id()) != visited.end();
}

void GBFSolver::clear() {
  while (!queue.empty()) queue.pop();
  free_nodes(this->nodes);
  this->visited.clear();
}

solution_t GBFSolver::solve(EightPuzzle& puzzle) {
  insert(puzzle, nullptr);

  while (!queue.empty()) {
    SolverNode* node = get_next();

    EightPuzzle& instance = node->puzzle;
    if (instance.is_solved()) {
      solution_t solution = get_path(node);
      clear();
      return solution;
    }

    if (visited[node->puzzle.get_id()] < node->moves) {
      continue;
    }

    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (auto possible_move : possible_moves) {
      if (!is_visited(possible_move)) {
        insert(possible_move, node);
      }
    }
  }

  clear();
  throw std::invalid_argument("Puzzle has no solution");
}
