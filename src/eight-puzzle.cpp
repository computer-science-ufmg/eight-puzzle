#include"../include/eight-puzzle.hpp"

EightPuzzle::EightPuzzle(eight_puzzle_intstance_t& instance) {
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      this->instance[i][j] = instance[i][j];

      if (this->instance[i][j] == 0) {
        this->empty_x = i;
        this->empty_y = j;
      }
    }
  }
}

EightPuzzle::EightPuzzle() {

}

EightPuzzle::~EightPuzzle() {
}

/* ===================== Static Begin ===================== */

EightPuzzle EightPuzzle::read_instance(std::istream& in) {
  eight_puzzle_intstance_t instance;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      in >> instance[i][j];
    }
  }
  return EightPuzzle(instance);
}

EightPuzzle EightPuzzle::read_instance(char const* args[]) {
  eight_puzzle_intstance_t instance;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      instance[i][j] = atoi(args[i * PUZZLE_INSTANCE_WIDTH + j]);
    }
  }
  return EightPuzzle(instance);
}

std::vector<EightPuzzle> EightPuzzle::get_possible_moves(eight_puzzle_intstance_t& instance) {
  std::vector<EightPuzzle> possible_moves;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      if (instance[i][j] == 0) {
        if (i > 0) {
          EightPuzzle possible_move(instance);
          possible_move.move(DOWN);
          possible_moves.push_back(possible_move);
        }
        if (i < PUZZLE_INSTANCE_HEIGHT - 1) {
          EightPuzzle possible_move(instance);
          possible_move.move(UP);
          possible_moves.push_back(possible_move);
        }
        if (j > 0) {
          EightPuzzle possible_move(instance);
          possible_move.move(RIGHT);
          possible_moves.push_back(possible_move);
        }
        if (j < PUZZLE_INSTANCE_WIDTH - 1) {
          EightPuzzle possible_move(instance);
          possible_move.move(LEFT);
          possible_moves.push_back(possible_move);
        }
        break;
      }
    }
  }
  return possible_moves;
}

void EightPuzzle::print_instance(eight_puzzle_intstance_t& instance, std::ostream& out) {
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      if (instance[i][j] == 0) {
        out << " ";
      }
      else {
        out << instance[i][j];
      }
      out << " ";
    }
    out << std::endl;
  }
  out << std::endl;
}

bool EightPuzzle::is_valid(eight_puzzle_intstance_t& instance) {
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

bool EightPuzzle::is_solved(eight_puzzle_intstance_t& instance) {
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

eight_puzzle_intstance_t& EightPuzzle::get_instance() {
  return this->instance;
}

void EightPuzzle::print_instance(std::ostream& out) {
  EightPuzzle::print_instance(this->instance, out);
}

bool EightPuzzle::is_valid() {
  return EightPuzzle::is_valid(this->instance);
}

bool EightPuzzle::is_solved() {
  return EightPuzzle::is_solved(this->instance);
}

void EightPuzzle::move(direction_t direction) {
  int x = this->empty_x, y = this->empty_y, nx, ny;

  switch (direction) {
  case DOWN:
    nx = x + 1;
    ny = y;
    break;
  case UP:
    nx = x - 1;
    ny = y;
    break;
  case RIGHT:
    nx = x;
    ny = y + 1;
    break;
  case LEFT:
    nx = x;
    ny = y - 1;
    break;
  }

  this->empty_x = nx;
  this->empty_y = ny;

  this->instance[x][y] = this->instance[nx][ny];
  this->instance[this->empty_x][this->empty_y] = 0;
}
