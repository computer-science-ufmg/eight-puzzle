#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../eight-puzzle.hpp"

class ISolver {
public:
  virtual ~ISolver() {}
  virtual void solve(EightPuzzle& puzzle) = 0;
};

#endif
