#include "../../include/heuristic/heuristic.hpp"

float IHeuristic::get_value(EightPuzzle& puzzle) {
  eight_puzzle_intstance_t& instance = puzzle.get_instance();
  return this->calculate(instance);
}

float IHeuristic::get_value(EightPuzzle* puzzle) {
  eight_puzzle_intstance_t& instance = puzzle->get_instance();
  return this->calculate(instance);
}
