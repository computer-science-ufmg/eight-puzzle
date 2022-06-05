#ifndef HEURISTC_HPP
#define HEURISTC_HPP

#include<vector>

#include "../eight-puzzle.hpp"

class IHeuristic {
private:
  virtual float calculate(eight_puzzle_intstance_t& instance) = 0;

public:
  virtual ~IHeuristic() {}

  float get_value(EightPuzzle& puzzle);
  float get_value(EightPuzzle* puzzle);
  virtual float max() = 0;
};

#endif
