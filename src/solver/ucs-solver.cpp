#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/ucs-solver.hpp"

UCSSolver::UCSSolver() {
}

UCSSolver::~UCSSolver() {
}

ucs_node_pair_t UCSSolver::get_node_pair(SolverNode* node) {
  return std::make_pair(node->moves, node);
}

void UCSSolver::insert(EightPuzzle& puzzle, SolverNode* parent) {
  SolverNode* new_node = create_solver_node(puzzle, parent);
  visited[puzzle.get_id()] = new_node->moves;
  queue.push(get_node_pair(new_node));
  nodes.push_back(new_node);
}

SolverNode* UCSSolver::get_next() {
  auto [_, node] = queue.top();
  queue.pop();
  return node;
}

bool UCSSolver::is_visited(EightPuzzle& puzzle) {
  return visited.find(puzzle.get_id()) != visited.end();
}

void UCSSolver::clear() {
  while (!queue.empty()) queue.pop();
  free_nodes(this->nodes);
  this->visited.clear();
}

solution_t UCSSolver::solve(EightPuzzle& puzzle) {

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

    for (auto possible_move : instance.get_possible_moves()) {
      if (!is_visited(possible_move)) {
        insert(possible_move, node);
      }
    }
  }

  clear();
  throw std::invalid_argument("Puzzle has no solution");
}
