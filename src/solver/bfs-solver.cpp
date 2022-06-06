#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/bfs-solver.hpp"

BFSSolver::BFSSolver() {
}

BFSSolver::~BFSSolver() {
}

SolverNode* BFSSolver::insert(EightPuzzle& puzzle, SolverNode* parent) {
  SolverNode* new_node = create_solver_node(puzzle, parent);
  nodes.push_back(new_node);
  queue.push(new_node);
  return new_node;
}

SolverNode* BFSSolver::get_next() {
  SolverNode* node = queue.front();
  queue.pop();
  return node;
}

bool BFSSolver::is_visited(EightPuzzle& puzzle) {
  return visited[puzzle.get_id()] == true;
}

void BFSSolver::clear() {
  while (!queue.empty()) queue.pop();
  free_nodes(this->nodes);
  this->visited.clear();
}

solution_t BFSSolver::solve(EightPuzzle& puzzle) {
  SolverNode* new_node = nullptr;

  new_node = insert(puzzle, nullptr);
  if (puzzle.is_solved()) {
    solution_t solution = get_path(new_node);
    clear();
    return solution;
  }

  while (!queue.empty()) {
    SolverNode* node = get_next();
    EightPuzzle& instance = node->puzzle;
    visited[instance.get_id()] = true;

    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (auto possible_move : possible_moves) {
      if (!is_visited(possible_move)) {
        new_node = insert(possible_move, node);
        if (possible_move.is_solved()) {
          solution_t solution = get_path(new_node);
          clear();
          return solution;
        }
      }
    }
  }

  clear();
  throw std::invalid_argument("Puzzle has no solution");
}
