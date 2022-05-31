#include<queue>

#include"../../include/solver/bfs-solver.hpp"

BFSSolver::BFSSolver() {
}

BFSSolver::~BFSSolver() {
}

void BFSSolver::solve(EightPuzzle& puzzle) {
  // std::queue<eight_puzzle_intstance_t> queue;

  // queue.push(puzzle.get_instance());

  // while (!queue.empty()) {
  //   eight_puzzle_intstance_t& instance = queue.front();
  //   queue.pop();

  //   if (EightPuzzle::is_solved(instance)) {
  //     return;
  //   }

  //   std::vector<eight_puzzle_intstance_t> possible_moves = puzzle.get_possible_moves(instance);
  //   for (int i = 0; i < possible_moves.size(); i++) {
  //     queue.push(possible_moves[i]);
  //   }
  // }
}
