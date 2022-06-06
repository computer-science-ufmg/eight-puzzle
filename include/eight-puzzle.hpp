#ifndef EIGHT_PUZZLE_HPP
#define EIGHT_PUZZLE_HPP

#include<iostream>
#include<vector>
#include<queue>

#define PUZZLE_INSTANCE_HEIGHT 3
#define PUZZLE_INSTANCE_WIDTH 3
#define PUZZLE_INSTANCE_SIZE (PUZZLE_INSTANCE_HEIGHT * PUZZLE_INSTANCE_WIDTH)

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define NO_MOVE 9999

typedef int direction_t;

typedef int eight_puzzle_intstance_t[PUZZLE_INSTANCE_HEIGHT][PUZZLE_INSTANCE_WIDTH];

class EightPuzzle {
private:
  eight_puzzle_intstance_t instance;
  int empty_x;
  int empty_y;
  int last_move = NO_MOVE;

  static int count_inversions(eight_puzzle_intstance_t& instance);

public:
  EightPuzzle(eight_puzzle_intstance_t& instance);
  EightPuzzle();
  ~EightPuzzle();

  eight_puzzle_intstance_t& get_instance();
  void print_instance(std::ostream& out = std::cout);
  bool is_valid();
  bool is_solved();
  bool is_solvable();
  std::vector<EightPuzzle> get_possible_moves();
  bool can_move(direction_t direction);
  void move(direction_t direction);
  std::string get_id();
  int get_last_move();

  static EightPuzzle read_instance(std::istream& in = std::cin);
  static EightPuzzle read_instance(char const* args[]);
  static void print_instance(eight_puzzle_intstance_t& instance, std::ostream& out = std::cout);
  static bool is_valid(eight_puzzle_intstance_t& instance);
  static bool is_solved(eight_puzzle_intstance_t& instance);
  static bool is_solvable(eight_puzzle_intstance_t& instance);
  static bool is_inverse_move(direction_t a, direction_t b);
};

#endif
