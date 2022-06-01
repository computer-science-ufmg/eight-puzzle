/**
 * @file ucs-solver.hpp
 * @brief A* solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef ASTAR_SOLVER_HPP
#define ASTAR_SOLVER_HPP

#include "./solver.hpp"

class AStarSolver : public ISolver {
private:

public:
  AStarSolver();
  ~AStarSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
