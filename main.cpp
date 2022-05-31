#include<iostream>
#include<stack>

#include"./include/eight-puzzle.hpp"
#include"./include/solver/solver.hpp"
#include"./include/solver/bfs-solver.hpp"

void play(EightPuzzle& puzzle) {
  puzzle.print_instance();
  while (!puzzle.is_solved()) {
    std::cout << "0: UP\n1: DOWN\n2: LEFT\n3: RIGHT\nEnter a direction: ";
    int direction;
    std::cin >> direction;
    puzzle.move(direction);
    puzzle.print_instance();
  }
  printf("Solved!\n");
}

ISolver* get_solver(char algorithm) {
  switch (algorithm) {
  case 'P':
    return new BFSSolver();
    break;

  default:
    return new BFSSolver();
    break;
  }
}

void solve(EightPuzzle& puzzle, ISolver* solver, bool print_solution) {
  SolverNode* solution_node = solver->solve(puzzle);
  std::stack<SolverNode*> moves;

  if (print_solution) {
    while (solution_node != nullptr) {
      moves.push(solution_node);
      solution_node = solution_node->parent;
    }
    while (!moves.empty()) {
      solution_node = moves.top();
      moves.pop();
      solution_node->puzzle.print_instance();
      delete solution_node;
    }
  }
}

int main(int argc, char const* argv[]) {
  EightPuzzle puzzle;

  if (argc >= 11) {
    puzzle = EightPuzzle::read_instance(argv + 2);
  }
  else {
    puzzle = EightPuzzle::read_instance();
  }

  if (!puzzle.is_valid()) {
    std::cout << "Invalid puzzle!\n";
    return 1;
  }

  std::cout << "Puzzle:\n";
  puzzle.print_instance();

  if (argc > 1) {
    char exec_option = argv[1][0];
    if (exec_option == 'P') {
      play(puzzle);
    }
    else {
      ISolver* solver = get_solver(exec_option);
      solve(puzzle, solver, true);
    }
  }

  return 0;
}
