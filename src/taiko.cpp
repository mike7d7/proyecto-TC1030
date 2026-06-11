#include "../headers/taiko.hpp"
#include <cmath>

// Caclular el accuracy de la partida utilizando las distintas precisiones.
// Usar play() antes de este método.
// Regresa:
//      La precisión (accuracy) de la partida
double Taiko::calc_accuracy() {
  double acc = (great + 0.5 * ok) / num_notes;
  return acc;
}

// Simular el juego de una partida
void Taiko::play() {
  num_notes = great + ok + miss;

  accuracy = calc_accuracy();
  score = calc_score();
  performance_points = calc_performance();
};

// Calcular la puntuación (normalizada a max. 1000000).
// Usar play() y calc_accuracy() antes de este método.
// Regresa:
//      La puntuación de la partida
int Taiko::calc_score() {
  int val = 1000000 * (0.7 * sqrt((double)max_combo / num_notes) +
                       0.3 * std::pow(accuracy, 10));
  return val;
};

// Calcular los puntos de rendimiento.
// Usar play() y calc_accuracy() antes de este método.
// Regresa:
//      Los puntos de rendimiento de la partida
int Taiko::calc_performance() {
  int perf = 12 * std::pow(star_rating, 2.2) * std::pow(accuracy, 6) *
             std::pow(0.97, miss) * sqrt((double)max_combo / num_notes);
  return perf;
};

// Regresa stringstream con los datos importantes para mostrarlos después.
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
