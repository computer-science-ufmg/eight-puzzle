#ifndef EIGHT_PUZZLE_HPP
#define EIGHT_PUZZLE_HPP

#include<iostream>

#define PUZZLE_INSTANCE_SIZE 8

typedef int eight_puzzle_intstance_t[PUZZLE_INSTANCE_SIZE];

class EightPuzzle {
private:
  eight_puzzle_intstance_t instance;


public:
  EightPuzzle(eight_puzzle_intstance_t instance);
  ~EightPuzzle();

  static EightPuzzle* read_instance(std::istream& in);
};

#endif
