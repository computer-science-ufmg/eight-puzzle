#include "../../include/solver/solver.hpp"

SolverNode* create_solver_node(EightPuzzle& puzzle, SolverNode* parent, int last_move) {
  if (parent != nullptr) {
    return new SolverNode{ puzzle, parent, parent->moves + 1, last_move };
  }
  else {
    return new SolverNode{ puzzle, parent, 0, last_move };
  }
}
