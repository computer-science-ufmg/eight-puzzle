#include"../include/eight-puzzle.hpp"

#include<sstream>

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

int EightPuzzle::count_inversions(eight_puzzle_intstance_t& instance) {
  int inversions = 0;

  for (int i = 0; i < PUZZLE_INSTANCE_SIZE; i++) {
    if (instance[i / PUZZLE_INSTANCE_WIDTH][i % PUZZLE_INSTANCE_WIDTH] == 0) {
      continue;
    }
    for (int j = i + 1; j < PUZZLE_INSTANCE_SIZE; j++) {
      if (instance[j / PUZZLE_INSTANCE_WIDTH][j % PUZZLE_INSTANCE_WIDTH] == 0) {
        continue;
      }
      if (instance[i / PUZZLE_INSTANCE_WIDTH][i % PUZZLE_INSTANCE_WIDTH] > instance[j / PUZZLE_INSTANCE_WIDTH][j % PUZZLE_INSTANCE_WIDTH]) {
        inversions++;
      }
    }
  }

  return inversions;
}

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
      int expected_value = ((i * PUZZLE_INSTANCE_WIDTH) + j + 1) % PUZZLE_INSTANCE_SIZE;
      if (instance[i][j] != expected_value) {
        return false;
      }
    }
  }
  return true;
}

bool EightPuzzle::is_solvable(eight_puzzle_intstance_t& instance) {
  int inversions = EightPuzzle::count_inversions(instance);
  return inversions % 2 == 0;
}

bool EightPuzzle::is_inverse_move(direction_t a, direction_t b) {
  return (a + b == UP + DOWN) || (a + b == LEFT + RIGHT);
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

bool EightPuzzle::is_solvable() {
  return EightPuzzle::is_solvable(this->instance);
}

bool EightPuzzle::can_move(direction_t direction) {
  switch (direction) {
  case DOWN:
    return this->empty_x + 1 < PUZZLE_INSTANCE_HEIGHT;
  case UP:
    return this->empty_x > 0;
  case RIGHT:
    return this->empty_y + 1 < PUZZLE_INSTANCE_WIDTH;
  case LEFT:
    return this->empty_y > 0;
  default:
    return false;
  }
}

void EightPuzzle::move(direction_t direction) {
  int x = this->empty_x, y = this->empty_y, nx, ny;

  if (!can_move(direction)) {
    return;
  }

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
  this->last_move = direction;

  this->instance[x][y] = this->instance[nx][ny];
  this->instance[this->empty_x][this->empty_y] = 0;
}

std::vector<EightPuzzle> EightPuzzle::get_possible_moves() {
  std::vector<EightPuzzle> possible_moves;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      if (instance[i][j] == 0) {
        if (can_move(DOWN)) {
          EightPuzzle possible_move(instance);
          possible_move.move(DOWN);
          possible_moves.push_back(possible_move);
        }
        if (can_move(UP)) {
          EightPuzzle possible_move(instance);
          possible_move.move(UP);
          possible_moves.push_back(possible_move);
        }
        if (can_move(RIGHT)) {
          EightPuzzle possible_move(instance);
          possible_move.move(RIGHT);
          possible_moves.push_back(possible_move);
        }
        if (can_move(LEFT)) {
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

std::string EightPuzzle::get_id() {
  std::stringstream ss;
  for (int i = 0; i < PUZZLE_INSTANCE_HEIGHT; i++) {
    for (int j = 0; j < PUZZLE_INSTANCE_WIDTH; j++) {
      ss << this->instance[i][j];
    }
  }
  return ss.str();
}

int EightPuzzle::get_last_move() {
  return last_move;
}
