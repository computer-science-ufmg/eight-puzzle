#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/human-solver.hpp"

HumanSolver::HumanSolver() {
}

HumanSolver::~HumanSolver() {
}

direction_t HumanSolver::get_direction(char dir_char) {
  switch (dir_char) {
  case 'w':
  case 'W':
    return UP;
  case 'a':
  case 'A':
    return LEFT;
  case 's':
  case 'S':
    return DOWN;
  case 'd':
  case 'D':
    return RIGHT;
  default:
    throw std::invalid_argument("Invalid direction");
  }
}

solution_t HumanSolver::solve(EightPuzzle& puzzle) {
  SolverNode* node = create_solver_node(puzzle, nullptr);
  node_vector_t nodes;
  char direction;

  system("clear");
  puzzle.print_instance();
  std::cout << "W: UP\nS: DOWN\nA: LEFT\nD: RIGHT\nEnter a direction: ";
  while (std::cin >> direction) {
    puzzle.move(get_direction(direction));

    node = create_solver_node(puzzle, node);
    nodes.push_back(node);

    system("clear");
    puzzle.print_instance();
    if (puzzle.is_solved()) {
      break;
    }
    std::cout << "W: UP\nS: DOWN\nA: LEFT\nD: RIGHT\nEnter a direction: ";
  }
  solution_t solution = get_path(node);
  free_nodes(nodes);
  printf("Solved!\n");
  return solution;
}
