/**
 * @file human-solver.hpp
 * @brief Manual solver. Whether it is complete or optimal depends on you.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef HUMAN_SOLVER_HPP
#define HUMAN_SOLVER_HPP

#include "./solver.hpp"

class HumanSolver : public ISolver {
private:

public:
  HumanSolver();
  ~HumanSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
