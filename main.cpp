#include<iostream>
#include<stack>

#include"./include/eight-puzzle.hpp"
#include"./include/solver/bfs-solver.hpp"
#include"./include/solver/ids-solver.hpp"
#include"./include/solver/ucs-solver.hpp"
#include"./include/solver/astar-solver.hpp"
#include"./include/solver/gbf-solver.hpp"
#include"./include/solver/hill-climbing-solver.hpp"

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
  case 'B':
    return new BFSSolver();

  case 'I':
    return new IDSSolver();

  case 'U':
    return new UCSSolver();

  case 'A':
    return new AStarSolver();

  case 'G':
    return new GBFSolver();

  case 'H':
    return new HillClimbingSolver();

  default:
    return new BFSSolver();
  }
}

void solve(EightPuzzle& puzzle, ISolver* solver, bool print_solution) {
  solution_t solution;
  try {
    solution = solver->solve(puzzle);
  }
  catch (std::invalid_argument& e) {
    std::cout << "Error solving puzzle: " << e.what() << std::endl;
    return;
  }
  catch (std::logic_error& e) {
    std::cout << "Something went terribly wrong: " << e.what() << std::endl;
    return;
  }

  std::cout << solution.size() << "\n";
  if (print_solution) {
    std::cout << '\n';
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

  bool print = strncmp("PRINT", argv[argc - 1], 5) == 0;

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
      solve(puzzle, solver, print);
    }
  }

  return 0;
}
