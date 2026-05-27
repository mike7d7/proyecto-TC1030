#include "../headers/taiko.hpp"
#include <cmath>

double Taiko::calc_accuracy() {
  double acc = (great + 0.5 * ok) / num_notes;
  return acc;
}

void Taiko::play() {
  num_notes = great + ok + miss;

  accuracy = calc_accuracy();
  score = calc_score();
  performance_points = calc_performance();
};

int Taiko::calc_score() {
  int val = 1000000 * (0.7 * sqrt((double)max_combo / num_notes) +
                       0.3 * std::pow(accuracy, 10));
  return val;
};

int Taiko::calc_performance() {
  int perf = 12 * std::pow(star_rating, 2.2) * std::pow(accuracy, 6) *
             std::pow(0.97, miss) * sqrt((double)max_combo / num_notes);
  return perf;
};

std::stringstream Taiko::show_results() {
  std::stringstream ss;
  ss << "█████ " << beatmap << " █████" << std::endl;
  ss << "Modo: Taiko" << std::endl;
  ss << "Número de notas: " << num_notes << std::endl;
  ss << "Accuracy: " << accuracy << std::endl;
  ss << "Puntuación: " << score << std::endl;
  ss << "Puntos de rendimiento: " << performance_points << std::endl;
  return ss;
}
