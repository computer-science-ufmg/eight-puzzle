/**
 * @file ucs-solver.hpp
 * @brief Hill climbing solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef HILL_CLIMBING_SOLVER_HPP
#define HILL_CLIMBING_SOLVER_HPP

#include "./solver.hpp"

class HillClimbingSolver : public ISolver {
private:

public:
  HillClimbingSolver();
  ~HillClimbingSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
