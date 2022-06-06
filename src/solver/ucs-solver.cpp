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
  std::map<std::string, int> visited;
  SolverNode* new_node = nullptr;

  new_node = create_solver_node(puzzle, nullptr);
  queue.push(new_node);
  nodes.push_back(new_node);
  visited[puzzle.get_id()] = new_node->moves;

  while (!queue.empty()) {
    SolverNode* node = queue.top();
    queue.pop();

    EightPuzzle& instance = node->puzzle;
    if (instance.is_solved()) {
      solution_t solution = get_path(node);
      free_nodes(nodes);
      return solution;
    }

    if (visited[node->puzzle.get_id()] < node->moves) {
      continue;
    }

    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (auto possible_move : possible_moves) {
      bool node_visited = visited.find(possible_move.get_id()) != visited.end();
      if (!node_visited) {
        new_node = create_solver_node(possible_move, node);
        visited[possible_move.get_id()] = new_node->moves;
        queue.push(new_node);
        nodes.push_back(new_node);
      }
    }
  }

  free_nodes(nodes);
  throw std::invalid_argument("Puzzle has no solution");
}
