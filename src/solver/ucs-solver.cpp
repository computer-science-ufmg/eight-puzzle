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
  // std::queue<SolverNode*> queue;
  // std::vector<SolverNode*> nodes;
  // std::map<std::string, bool> visited;
  // SolverNode* new_node = nullptr;

  // if (!puzzle.is_valid()) {
  //   throw std::invalid_argument("Cannot solve invalid puzzle");
  // }

  // new_node = create_solver_node(puzzle, nullptr);
  // queue.push(new_node);
  // nodes.push_back(new_node);

  std::logic_error("Not implemented yet");
}
