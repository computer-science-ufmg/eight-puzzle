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

std::string IDSSolver::compose_id(EightPuzzle& puzzle, int moves) {
  std::stringstream ss;
  ss << moves << puzzle.get_id();
  return ss.str();
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

  while (this->max_depth < this->limit_depth) {
    this->max_depth++;
    visited.clear();

    SolverNode* starting_node = create_solver_node(puzzle, nullptr);
    nodes.push_back(starting_node);
    stack.push(starting_node);

    while (!stack.empty()) {
      SolverNode* node = stack.top();
      EightPuzzle& instance = node->puzzle;
      stack.pop();

      visited[compose_id(instance, node->moves)] = true;
      if (instance.is_solved()) {
        free_nodes(nodes);
        return get_path(node);
      }

      if (node->moves == this->max_depth) {
        continue;
      }

      std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
      for (std::vector<EightPuzzle>::iterator it = possible_moves.begin(); it != possible_moves.end(); ++it) {
        EightPuzzle possible_move = *it;
        new_node = create_solver_node(possible_move, node);

        bool node_visited = visited[compose_id(possible_move, new_node->moves)] == true;

        if (!node_visited) {
          stack.push(new_node);
          nodes.push_back(new_node);
        }
        else {
          delete new_node;
        }
      }
    }
    free_nodes(nodes);
  }

  free_nodes(nodes);
  throw std::invalid_argument("Puzzle either has no solution, or it could not be found within the limit depth");
}
