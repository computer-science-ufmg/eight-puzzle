/**
 * @file hill-climbing-solver.hpp
 * @brief Hill climbing solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef HILL_CLIMBING_SOLVER_HPP
#define HILL_CLIMBING_SOLVER_HPP

#include "./solver.hpp"

#include "../heuristic/heuristic.hpp"

class HillClimbingSolver : public ISolver {
private:
  IHeuristic* heuristic = nullptr;

public:
  HillClimbingSolver(IHeuristic* heuristic);
  ~HillClimbingSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
