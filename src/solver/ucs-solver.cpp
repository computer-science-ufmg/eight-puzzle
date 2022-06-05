#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/ucs-solver.hpp"

UCSSolver::UCSSolver() {
}

UCSSolver::~UCSSolver() {
}

solution_t UCSSolver::solve(EightPuzzle& puzzle) {
  std::priority_queue<SolverNode*> queue;
  std::vector<SolverNode*> nodes;
  std::map<std::string, bool> visited;
  SolverNode* new_node = nullptr;

  if (!puzzle.is_valid()) {
    throw std::invalid_argument("Cannot solve invalid puzzle");
  }

  new_node = create_solver_node(puzzle, nullptr);
  queue.push(new_node);
  nodes.push_back(new_node);

  while (!queue.empty()) {
    SolverNode* node = queue.top();
    queue.pop();

    EightPuzzle& instance = node->puzzle;
    visited[instance.get_id()] = true;
    if (instance.is_solved()) {
      solution_t solution = get_path(node);
      free_nodes(nodes);
      return solution;
    }

    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (std::vector<EightPuzzle>::iterator it = possible_moves.begin(); it != possible_moves.end(); ++it) {
      EightPuzzle possible_move = *it;

      bool node_visited = visited[possible_move.get_id()] == true;
      bool is_inverse_parent_move = EightPuzzle::is_inverse_move(possible_move.get_last_move(), node->last_move);
      bool valid = possible_move.is_valid();

      if (!node_visited && !is_inverse_parent_move && valid) {
        new_node = create_solver_node(possible_move, node);
        queue.push(new_node);
        nodes.push_back(new_node);
      }
    }
  }

  free_nodes(nodes);
  throw std::invalid_argument("Puzzle has no solution");
}
