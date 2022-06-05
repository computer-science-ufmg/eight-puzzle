#ifndef MISS_COUNT_HEURISTIC_HPP
#define MISS_COUNT_HEURISTIC_HPP

#include"./heuristic.hpp"

class MissCountHeuristic : public IHeuristic {
private:
  float calculate(eight_puzzle_intstance_t& instance);

public:
  MissCountHeuristic();
  ~MissCountHeuristic();

  float max();
};

#endif

