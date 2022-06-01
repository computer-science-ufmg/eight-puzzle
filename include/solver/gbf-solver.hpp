/**
 * @file ucs-solver.hpp
 * @brief Greedy best-first solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef GBF_SOLVER_HPP
#define GBF_SOLVER_HPP

#include "./solver.hpp"

class GBFSolver : public ISolver {
private:

public:
  GBFSolver();
  ~GBFSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
