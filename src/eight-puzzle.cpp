#include"../include/eight-puzzle.hpp"

EightPuzzle::EightPuzzle(eight_puzzle_intstance_t instance) {
  for (int i = 0; i < PUZZLE_INSTANCE_SIZE; i++) {
    this->instance[i] = instance[i];
  }
}

EightPuzzle::~EightPuzzle() {
}

EightPuzzle* EightPuzzle::read_instance(std::istream& in) {
  eight_puzzle_intstance_t instance;
  for (int i = 0; i < PUZZLE_INSTANCE_SIZE; i++) {
    in >> instance[i];
  }
  return new EightPuzzle(instance);
}
