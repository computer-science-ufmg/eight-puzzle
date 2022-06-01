/**
 * @file ucs-solver.hpp
 * @brief Uniform cost solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef UCS_SOLVER_HPP
#define UCS_SOLVER_HPP

#include "./solver.hpp"

class UCSSolver : public ISolver {
private:

public:
  UCSSolver();
  ~UCSSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
