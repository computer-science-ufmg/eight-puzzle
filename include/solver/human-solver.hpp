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
  direction_t get_direction(char dir_char);

public:
  HumanSolver();
  ~HumanSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
