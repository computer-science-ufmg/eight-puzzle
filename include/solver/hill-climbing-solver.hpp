/**
 * @file hill-climbing-solver.hpp
 * @brief Hill climbing solver implementation. Not complete, not optimal algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef HILL_CLIMBING_SOLVER_HPP
#define HILL_CLIMBING_SOLVER_HPP

#define MAX_LATERAL_MOVEMENTS 8

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
