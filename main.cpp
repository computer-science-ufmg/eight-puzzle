#include<iostream>
#include<stack>
#include <chrono>

#include"./include/eight-puzzle.hpp"

#include"./include/solver/bfs-solver.hpp"
#include"./include/solver/ids-solver.hpp"
#include"./include/solver/ucs-solver.hpp"
#include"./include/solver/astar-solver.hpp"
#include"./include/solver/gbf-solver.hpp"
#include"./include/solver/hill-climbing-solver.hpp"
#include"./include/solver/human-solver.hpp"

#include"./include/heuristic/miss-count-heuristic.hpp"


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
    return new GBFSolver(new MissCountHeuristic());

  case 'H':
    return new HillClimbingSolver(new MissCountHeuristic());

  case 'P':
    return new HumanSolver();

  default:
    return new BFSSolver();
  }
}

void solve(EightPuzzle& puzzle, ISolver* solver, bool print_solution, bool timed) {
  solution_t solution;
  long long elapsed_time;

  try {
    auto start = std::chrono::steady_clock::now();
    solution = solver->solve(puzzle);
    auto end = std::chrono::steady_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  }
  catch (std::invalid_argument& e) {
    std::cout << "Error solving puzzle: " << e.what() << std::endl;
    return;
  }
  catch (std::logic_error& e) {
    std::cout << "Something went terribly wrong: " << e.what() << std::endl;
    return;
  }

  if (timed) {
    std::cout << solution.size() << ' ' << elapsed_time << "\n";
  }
  else {
    std::cout << solution.size() << "\n";
  }
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
  bool timed = strncmp("TIME", argv[argc - 1], 5) == 0;

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

  if (!puzzle.is_solvable()) {
    std::cout << "Puzzle is not solvable!\n";
    return 1;
  }

  if (argc > 1) {
    char exec_option = argv[1][0];
    ISolver* solver = get_solver(exec_option);
    solve(puzzle, solver, print, timed);
  }

  return 0;
}
