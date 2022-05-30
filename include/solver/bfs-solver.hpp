#ifndef BFS_SOLVER_HPP
#define BFS_SOLVER_HPP

#include "./solver.hpp"

class BFSSolver : public ISolver {
private:

public:
  BFSSolver();
  ~BFSSolver();

  void solve(EightPuzzle& puzzle);
};

#endif
