#include"../include/eight-puzzle.hpp"

EightPuzzle::EightPuzzle(eight_puzzle_intstance_t instance) {
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      this->instance[i][j] = instance[i][j];
    }
  }
}

EightPuzzle::~EightPuzzle() {
}

/* ===================== Static Begin ===================== */

EightPuzzle* EightPuzzle::read_instance(std::istream& in) {
  eight_puzzle_intstance_t instance;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      in >> instance[i][j];
    }
  }
  return new EightPuzzle(instance);
}

EightPuzzle* EightPuzzle::read_instance(char const* args[]) {
  eight_puzzle_intstance_t instance;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      instance[i][j] = atoi(args[i * PUZZLE_INSTANCE_WIDTH + j]);
    }
  }
  return new EightPuzzle(instance);
}

void EightPuzzle::print_instance(eight_puzzle_intstance_t instance, std::ostream& out) {
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      out << instance[i][j] << " ";
    }
    out << std::endl;
  }
  out << std::endl;
}

bool EightPuzzle::is_valid(eight_puzzle_intstance_t instance) {
  int positions[PUZZLE_INSTANCE_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      if (instance[i][j] < 0 || instance[i][j] >= PUZZLE_INSTANCE_SIZE) {
        return false;
      }
      if (positions[instance[i][j]] != 0) {
        return false;
      }
      positions[instance[i][j]] = 1;
    }
  }
  return true;
}

bool EightPuzzle::is_solved(eight_puzzle_intstance_t instance) {
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      int expected_value = ((i * PUZZLE_INSTANCE_WIDTH) + j + 1) % (PUZZLE_INSTANCE_SIZE);
      if (instance[i][j] != expected_value) {
        return false;
      }
    }
  }
  return true;
}

/* ====================== Static End ====================== */

void EightPuzzle::print_instance(std::ostream& out) {
  EightPuzzle::print_instance(this->instance, out);
}

bool EightPuzzle::is_valid() {
  return EightPuzzle::is_valid(this->instance);
}

bool EightPuzzle::is_solved() {
  return EightPuzzle::is_solved(this->instance);
}
