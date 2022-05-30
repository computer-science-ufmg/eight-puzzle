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

  if (eight_puzzle.is_valid()) {
    std::cout << "Valid!" << std::endl;
  }
  else {
    std::cout << "Not valid!" << std::endl;
  }

  if (eight_puzzle.is_solved()) {
    std::cout << "Solved!" << std::endl;
  }
  else {
    std::cout << "Not solved!" << std::endl;
  }

  return 0;
}
