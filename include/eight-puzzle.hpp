#ifndef EIGHT_PUZZLE_HPP
#define EIGHT_PUZZLE_HPP

#include<iostream>

#define PUZZLE_INSTANCE_HEIGHT 3
#define PUZZLE_INSTANCE_WIDTH 3
#define PUZZLE_INSTANCE_SIZE PUZZLE_INSTANCE_HEIGHT * PUZZLE_INSTANCE_WIDTH

typedef int eight_puzzle_intstance_t[PUZZLE_INSTANCE_HEIGHT][PUZZLE_INSTANCE_WIDTH];

class EightPuzzle {
private:
  eight_puzzle_intstance_t instance;

public:
  EightPuzzle(eight_puzzle_intstance_t& instance);
  EightPuzzle();
  ~EightPuzzle();

  void print_instance(std::ostream& out = std::cout);
  bool is_valid();
  bool is_solved();

  static EightPuzzle read_instance(std::istream& in = std::cin);
  static EightPuzzle read_instance(char const* args[]);
  static void print_instance(eight_puzzle_intstance_t& instance, std::ostream& out = std::cout);
  static bool is_valid(eight_puzzle_intstance_t& instance);
  static bool is_solved(eight_puzzle_intstance_t& instance);
};

#endif
