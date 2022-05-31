#include<queue>
#include<map>

#include"../../include/solver/bfs-solver.hpp"

BFSSolver::BFSSolver() {
}

BFSSolver::~BFSSolver() {
}

SolverNode* BFSSolver::solve(EightPuzzle& puzzle) {
  std::queue<SolverNode*> queue;
  std::map<std::string, bool> visited;

  queue.push(create_solver_node(puzzle, nullptr, 0));

  while (!queue.empty()) {
    SolverNode* node = queue.front();
    queue.pop();

    EightPuzzle& instance = node->puzzle;
    visited[instance.get_id()] = true;
    if (instance.is_solved()) {
      return node;
    }

    std::vector<EightPuzzle> possible_moves = instance.get_possible_moves();
    for (std::vector<EightPuzzle>::iterator it = possible_moves.begin(); it != possible_moves.end(); ++it) {
      EightPuzzle possible_move = *it;
      if (!visited[possible_move.get_id()]) {
        queue.push(create_solver_node(possible_move, node, possible_move.get_last_move()));
      }
    }
  }

  return nullptr;
}
