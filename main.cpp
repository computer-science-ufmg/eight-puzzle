#include<iostream>

#include"./include/eight-puzzle.hpp"

int main(int argc, char const* argv[]) {
  EightPuzzle eight_puzzle;

  if (argc >= 11) {
    eight_puzzle = EightPuzzle::read_instance(argv + 2);
  }
  else {
    eight_puzzle = EightPuzzle::read_instance();
  }

  eight_puzzle.print_instance();

  if (argc > 1 && argv[1][0] == 'P') {
    while (!eight_puzzle.is_solved()) {
      std::cout << "0: UP\n1: DOWN\n2: LEFT\n3: RIGHT\nEnter a direction: ";
      int direction;
      std::cin >> direction;
      eight_puzzle.move(direction);
      eight_puzzle.print_instance();
    }
    printf("Solved!\n");
  }

  return 0;
}
