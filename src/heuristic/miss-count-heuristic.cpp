#include "../../include/heuristic/miss-count-heuristic.hpp"

MissCountHeuristic::MissCountHeuristic(/* args */) {
}

MissCountHeuristic::~MissCountHeuristic() {
}

float MissCountHeuristic::calculate(eight_puzzle_intstance_t& instance) {
  int miss = 0;

  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      int expected_value = ((i * PUZZLE_INSTANCE_WIDTH) + j + 1) % (PUZZLE_INSTANCE_SIZE);
      if (instance[i][j] != expected_value) {
        miss += 1.0;
      }
    }
  }
  return miss;
}

float MissCountHeuristic::max() {
  return 1.0 * PUZZLE_INSTANCE_SIZE;
}
