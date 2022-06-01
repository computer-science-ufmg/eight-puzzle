/**
 * @file ids-solver.hpp
 * @brief Iterative deepening search solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef IDS_SOLVER_HPP
#define IDS_SOLVER_HPP

#include "./solver.hpp"

class IDSSolver : public ISolver {
private:
  int limit_depth = 100;
  int max_depth = 0;

  std::string compose_id(EightPuzzle& puzzle, int moves);

public:
  IDSSolver();
  ~IDSSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
