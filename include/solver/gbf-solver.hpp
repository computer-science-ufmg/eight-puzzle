/**
 * @file gbf-solver.hpp
 * @brief Greedy best-first solver implementation. Not optimal and complete algorithm.
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
typedef std::priority_queue<gbf_node_pair_t> gbf_queue_t;

class GBFSolver : public ISolver {
private:
  IHeuristic* heuristic;
  gbf_queue_t queue;
  node_vector_t nodes;
  std::map<std::string, bool> visited;

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
