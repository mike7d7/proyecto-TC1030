#include "../headers/standard.hpp"
#include <cmath>
#include <ostream>
#include <sstream>

void Standard::play() {
  num_notes = great + ok + meh + miss;

  accuracy = calc_accuracy();
  score = calc_score();
  performance_points = calc_performance();
}

int Standard::calc_score() {
  int max = num_notes * 300;
  double current = (great * 300) + (ok * 100) + (meh * 50);
  double weighted = current * 5.5 * ((double)max_combo / num_notes);
  double max_score = max * 6.85;
  int final_val =
      weighted / max_score * 1000000 - std::pow(weighted / 10000, 2);
  return final_val;
};

int Standard::calc_performance() {
  int perf = 25 * std::pow(star_rating - 1.8, 2) *
             std::pow(accuracy / 0.98, 6) *
             std::pow(max_combo / num_notes, 0.8) * std::pow(0.97, miss);
  return perf;
};

double Standard::calc_accuracy() {
  double total = 0.0;
  // https://osu.ppy.sh/wiki/en/Gameplay/Judgement/osu%21
  total += (great * 100) + (ok * 33.33) + (meh * 16.67);
  double acc = total / (num_notes * 100);
  return acc;
}

std::stringstream Standard::show_results() {
  std::stringstream ss;
  ss << "█████ " << beatmap << " █████" << std::endl;
  ss << "Modo: Standard" << std::endl;
  ss << "Número de notas: " << num_notes << std::endl;
  ss << "Accuracy: " << accuracy << std::endl;
  ss << "Puntuación: " << score << std::endl;
  ss << "Puntos de rendimiento: " << performance_points << std::endl;
  return ss;
}
