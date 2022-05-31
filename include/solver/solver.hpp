#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../eight-puzzle.hpp"

struct SolverNode {
  EightPuzzle puzzle;
  SolverNode* parent;
  int moves;
  int last_move;
};

class ISolver {
public:
  virtual ~ISolver() {}
  virtual SolverNode* solve(EightPuzzle& puzzle) = 0;
};

SolverNode* create_solver_node(EightPuzzle& puzzle, SolverNode* parent, int last_move);

#endif
