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

  int operator<(SolverNode const& other) const {
    return (this->moves < other.moves);
  }

  int operator>(SolverNode const& other) const {
    return other < *this;
  }

  int operator>=(SolverNode const& other) const {
    return !(*this < other);
  }

  int operator<=(SolverNode const& other) const {
    return !(other < *this);
  }

  int operator==(SolverNode const& other) const {
    return other.moves == this->moves;
  }

  int operator!=(SolverNode const& other) const {
    return !(other == *this);
  }
};

typedef std::vector<SolverNode*> node_vector_t;

class ISolver {
public:
  virtual ~ISolver() {}
  virtual solution_t solve(EightPuzzle& puzzle) = 0;

  void free_nodes(node_vector_t& nodes);
  std::queue<direction_t> get_path(SolverNode* node);
};

SolverNode* create_solver_node(EightPuzzle& puzzle, SolverNode* parent);

#endif
