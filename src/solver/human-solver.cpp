#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/human-solver.hpp"

HumanSolver::HumanSolver() {
}

HumanSolver::~HumanSolver() {
}

solution_t HumanSolver::solve(EightPuzzle& puzzle) {
  SolverNode* node = create_solver_node(puzzle, nullptr);
  std::vector<SolverNode*> nodes;

  system("clear");
  puzzle.print_instance();
  while (!puzzle.is_solved()) {
    std::cout << "0: UP\n1: DOWN\n2: LEFT\n3: RIGHT\nEnter a direction: ";
    int direction;
    std::cin >> direction;
    puzzle.move(direction);

    node = create_solver_node(puzzle, node);
    nodes.push_back(node);

    system("clear");
    puzzle.print_instance();
  }
  solution_t solution = get_path(node);
  free_nodes(nodes);
  printf("Solved!\n");
  return solution;
}
