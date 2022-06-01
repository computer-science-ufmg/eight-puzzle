/**
 * @file bfs-solver.hpp
 * @brief Breadth-first search solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef BFS_SOLVER_HPP
#define BFS_SOLVER_HPP

#include "./solver.hpp"

class BFSSolver : public ISolver {
private:

public:
  BFSSolver();
  ~BFSSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
