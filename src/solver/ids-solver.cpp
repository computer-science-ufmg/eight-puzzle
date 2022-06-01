#include<stack>
#include<map>
#include<vector>
#include<exception>
#include<sstream>

#include"../../include/solver/ids-solver.hpp"

IDSSolver::IDSSolver() {
}

IDSSolver::~IDSSolver() {
}

solution_t IDSSolver::solve(EightPuzzle& puzzle) {
  std::stack<SolverNode*> stack;
  std::vector<SolverNode*> nodes;
  std::map<std::string, bool> visited;
  SolverNode* new_node = nullptr;

  if (!puzzle.is_valid()) {
    throw std::invalid_argument("Cannot solve invalid puzzle");
  }

  this->max_depth = 0;
  SolverNode* starting_node = create_solver_node(puzzle, nullptr);
  nodes.push_back(starting_node);

  while (this->max_depth < this->limit_depth) {
    this->max_depth++;
    visited.clear();
    stack.push(starting_node);

    while (!stack.empty()) {
      SolverNode* node = stack.top();
      EightPuzzle& instance = node->puzzle;
      stack.pop();

      visited[instance.get_id()] = true;
      if (instance.is_solved()) {
        return get_path(node);
      }

      if (node->moves == this->max_depth) {
        continue;
      }

      std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
      for (std::vector<EightPuzzle>::iterator it = possible_moves.begin(); it != possible_moves.end(); ++it) {
        EightPuzzle possible_move = *it;

        bool node_visited = visited[possible_move.get_id()] == true;
        bool is_inverse_parent_move = EightPuzzle::is_inverse_move(possible_move.get_last_move(), node->last_move);
        bool valid = possible_move.is_valid();

        if (!node_visited && !is_inverse_parent_move && valid) {
          new_node = create_solver_node(possible_move, node);
          stack.push(new_node);
          nodes.push_back(new_node);
        }
      }
    }
  }

  free_nodes(nodes);
  throw std::logic_error("Unreachable exception: puzzle either has no solution, or it could not be found within the limit depth");
}
