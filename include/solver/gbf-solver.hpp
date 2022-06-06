/**
 * @file gbf-solver.hpp
 * @brief Greedy best-first solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef GBF_SOLVER_HPP
#define GBF_SOLVER_HPP

#include<map>
#include<queue>

#include "./solver.hpp"
#include "../heuristic/heuristic.hpp"


typedef std::pair<float, SolverNode*> gbf_node_pair_t;

class GBFSolver : public ISolver {
private:
  IHeuristic* heuristic;
  std::priority_queue<gbf_node_pair_t> queue;
  std::vector<SolverNode*> nodes;
  std::map<std::string, int> visited;

  void insert(EightPuzzle& puzzle, SolverNode* parent);
  SolverNode* get_next();
  gbf_node_pair_t get_node_pair(SolverNode* node);
  bool is_visited(EightPuzzle& puzzle);
  void clear();

public:
  GBFSolver(IHeuristic* heuristic);
  ~GBFSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
