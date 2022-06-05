#include<queue>
#include<map>
#include<vector>
#include<exception>

#include"../../include/solver/hill-climbing-solver.hpp"

HillClimbingSolver::HillClimbingSolver(IHeuristic* heuristic) {
  this->heuristic = heuristic;
}

HillClimbingSolver::~HillClimbingSolver() {
  delete this->heuristic;
}

solution_t HillClimbingSolver::solve(EightPuzzle& puzzle) {
  std::vector<SolverNode*> nodes;
  SolverNode* node = create_solver_node(puzzle, nullptr);
  float current_value = this->heuristic->get_value(node->puzzle);
  int k = 0;

  nodes.push_back(node);

  while (k < MAX_LATERAL_MOVEMENTS && current_value != 0.0) {
    std::vector<EightPuzzle> neighrbours = node->puzzle.get_possible_moves();
    EightPuzzle best_neighbour;
    float best_neighbour_value = this->heuristic->max();

    if (neighrbours.size() == 0) {
      break;
    }
    for (auto move : neighrbours) {
      float value = this->heuristic->get_value(move);
      if (value < best_neighbour_value) {
        best_neighbour_value = value;
        best_neighbour = move;
      }
    }

    if (best_neighbour_value <= current_value) {
      if (best_neighbour_value == current_value) {
        k++;
      }
      else {
        k = 0;
      }
      node = create_solver_node(best_neighbour, node);
      nodes.push_back(node);
      current_value = best_neighbour_value;
    }
    else {
      break;
    }
  }
  if (!node->puzzle.is_solved()) {
    this->free_nodes(nodes);
    throw std::logic_error("hill climging failed");
  }

  solution_t solution = this->get_path(node);
  this->free_nodes(nodes);
  return solution;
}
