#include<queue>
#include<stack>

#include "../../include/solver/solver.hpp"

SolverNode* create_solver_node(EightPuzzle& puzzle, SolverNode* parent) {
  if (parent != nullptr) {
    return new SolverNode{ puzzle, parent, parent->moves + 1, puzzle.get_last_move() };
  }
  else {
    return new SolverNode{ puzzle, parent, 0, puzzle.get_last_move() };
  }
}

std::queue<direction_t> ISolver::get_path(SolverNode* node) {
  std::stack<direction_t> inverse_path;
  std::queue<direction_t> path;

  SolverNode* current_node = node;
  while (current_node != nullptr) {
    if (current_node->last_move != NO_MOVE) {
      inverse_path.push(current_node->last_move);
    }
    current_node = current_node->parent;
  }
  while (!inverse_path.empty()) {
    path.push(inverse_path.top());
    inverse_path.pop();
  }
  return path;
}

void ISolver::free_nodes(std::vector<SolverNode*>& nodes) {
  while (!nodes.empty()) {
    SolverNode* node = nodes.back();
    nodes.pop_back();
    delete node;
  }
}
