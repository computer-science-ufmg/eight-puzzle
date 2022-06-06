#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/bfs-solver.hpp"

BFSSolver::BFSSolver() {
}

BFSSolver::~BFSSolver() {
}

solution_t BFSSolver::solve(EightPuzzle& puzzle) {
  std::queue<SolverNode*> queue;
  std::vector<SolverNode*> nodes;
  std::map<std::string, bool> visited;
  SolverNode* new_node = nullptr;

  if (!puzzle.is_valid()) {
    throw std::invalid_argument("Cannot solve invalid puzzle");
  }

  new_node = create_solver_node(puzzle, nullptr);
  nodes.push_back(new_node);
  if (puzzle.is_solved()) {
    solution_t solution = get_path(new_node);
    free_nodes(nodes);
    return solution;
  }
  queue.push(new_node);

  while (!queue.empty()) {
    SolverNode* node = queue.front();
    queue.pop();

    EightPuzzle& instance = node->puzzle;
    visited[instance.get_id()] = true;


    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (auto possible_move : possible_moves) {
      bool node_visited = visited[possible_move.get_id()] == true;
      if (!node_visited) {
        new_node = create_solver_node(possible_move, node);
        nodes.push_back(new_node);
        if (possible_move.is_solved()) {
          solution_t solution = get_path(new_node);
          free_nodes(nodes);
          return solution;
        }
        queue.push(new_node);
      }
    }
  }

  free_nodes(nodes);
  throw std::invalid_argument("Puzzle has no solution");
}
