/**
 * @file bfs-solver.hpp
 * @brief Breadth-first search solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef BFS_SOLVER_HPP
#define BFS_SOLVER_HPP

#include<queue>
#include<map>
#include<vector>

#include "./solver.hpp"

class BFSSolver : public ISolver {
private:
  std::queue<SolverNode*> queue;
  std::vector<SolverNode*> nodes;
  std::map<std::string, bool> visited;

  SolverNode* insert(EightPuzzle& puzzle, SolverNode* parent);
  SolverNode* get_next();
  bool is_visited(EightPuzzle& puzzle);
  void clear();

public:
  BFSSolver();
  ~BFSSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
