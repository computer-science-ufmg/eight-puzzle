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
  solution_t solution;
  try {
    solution = solver->solve(puzzle);
  }
  catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
    return;
  }
  catch (std::logic_error& e) {
    std::cout << "Something went terribly wrong: " << e.what() << std::endl;
    return;
  }

  if (print_solution) {
    std::cout << solution.size() << "\n\n";
    puzzle.print_instance();
    while (!solution.empty()) {
      direction_t move = solution.front();
      solution.pop();
      puzzle.move(move);
      puzzle.print_instance();
    }
  }
}

int main(int argc, char const* argv[]) {
  EightPuzzle puzzle;

  if (argc >= 2 + PUZZLE_INSTANCE_SIZE) {
    puzzle = EightPuzzle::read_instance(argv + 2);
  }
  else {
    puzzle = EightPuzzle::read_instance();
  }

  if (!puzzle.is_valid()) {
    std::cout << "Invalid puzzle!\n";
    return 1;
  }

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
