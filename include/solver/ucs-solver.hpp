/**
 * @file ucs-solver.hpp
 * @brief Uniform cost solver implementation. Optimal and complete algorithm.
 * @author Luiz Philipe <luizphilippe@dcc.ufmg.br>
 * @version 0.1
 *
 */

#ifndef UCS_SOLVER_HPP
#define UCS_SOLVER_HPP

#include<vector>
#include<queue>
#include<map>

#include "./solver.hpp"

typedef std::pair<int, SolverNode*> ucs_node_pair_t;
typedef std::priority_queue<ucs_node_pair_t, std::vector<ucs_node_pair_t>, std::greater<ucs_node_pair_t>> ucs_queue_t;

class UCSSolver : public ISolver {
private:
  ucs_queue_t queue;
  node_vector_t nodes;
  std::map<std::string, int> visited;

  void insert(EightPuzzle& puzzle, SolverNode* parent);
  SolverNode* get_next();
  ucs_node_pair_t get_node_pair(SolverNode* node);
  bool is_visited(EightPuzzle& puzzle);
  void clear();

public:
  UCSSolver();
  ~UCSSolver();

  solution_t solve(EightPuzzle& puzzle);
};

#endif
