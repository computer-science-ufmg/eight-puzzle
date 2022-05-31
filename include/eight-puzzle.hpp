#ifndef EIGHT_PUZZLE_HPP
#define EIGHT_PUZZLE_HPP

#include<iostream>
#include<vector>
#include<queue>

#define PUZZLE_INSTANCE_HEIGHT 3
#define PUZZLE_INSTANCE_WIDTH 3
#define PUZZLE_INSTANCE_SIZE PUZZLE_INSTANCE_HEIGHT * PUZZLE_INSTANCE_WIDTH

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef int direction_t;

typedef int eight_puzzle_intstance_t[PUZZLE_INSTANCE_HEIGHT][PUZZLE_INSTANCE_WIDTH];

class EightPuzzle {
private:
  eight_puzzle_intstance_t instance;
  int empty_x;
  int empty_y;
  int last_move = -1;

public:
  EightPuzzle(eight_puzzle_intstance_t& instance);
  EightPuzzle();
  ~EightPuzzle();

  eight_puzzle_intstance_t& get_instance();
  void print_instance(std::ostream& out = std::cout);
  bool is_valid();
  bool is_solved();
  std::vector<EightPuzzle> get_possible_moves();
  void move(direction_t direction);
  std::string get_id();
  int get_last_move();

  static EightPuzzle read_instance(std::istream& in = std::cin);
  static EightPuzzle read_instance(char const* args[]);
  static void print_instance(eight_puzzle_intstance_t& instance, std::ostream& out = std::cout);
  static bool is_valid(eight_puzzle_intstance_t& instance);
  static bool is_solved(eight_puzzle_intstance_t& instance);
};

#endif
