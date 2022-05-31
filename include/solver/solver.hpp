#ifndef SOLVER_HPP
#define SOLVER_HPP

#include<vector>

#include "../eight-puzzle.hpp"

typedef std::queue<direction_t> solution_t;

struct SolverNode {
  EightPuzzle puzzle;
  SolverNode* parent;
  int moves;
  int last_move;
};

class ISolver {
public:
  virtual ~ISolver() {}
  virtual solution_t solve(EightPuzzle& puzzle) = 0;

  void free_nodes(std::vector<SolverNode*>& nodes);
  std::queue<direction_t> get_path(SolverNode* node);
};

SolverNode* create_solver_node(EightPuzzle& puzzle, SolverNode* parent);

#endif
