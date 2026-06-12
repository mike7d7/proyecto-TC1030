#include "../headers/taiko.hpp"
#include <cmath>

// Caclular el accuracy de la partida utilizando las distintas precisiones.
// Regresa:
//      La precisión (accuracy) de la partida
double Taiko::calc_accuracy() {
  double acc = (great + 0.5 * ok) / num_notes;
  return acc;
}

// Calcular la puntuación (normalizada a max. 1000000).
// Regresa:
//      La puntuación de la partida
int Taiko::calc_score() {
  int val = 1000000 * (0.7 * sqrt((double)max_combo / num_notes) +
                       0.3 * std::pow(accuracy, 10));
  return val;
};

// Calcular los puntos de rendimiento.
// Regresa:
//      Los puntos de rendimiento de la partida
int Taiko::calc_performance() {
  int perf = 12 * std::pow(star_rating, 2.2) * std::pow(accuracy, 6) *
             std::pow(0.97, miss) * sqrt((double)max_combo / num_notes);
  return perf;
};

// Simular el juego de una partida
// Utiliza las 3 funciones de calc_*() en un orden específico para evitar
// errores.
void Taiko::play() {
  num_notes = great + ok + miss;

  accuracy = calc_accuracy();
  score = calc_score();
  performance_points = calc_performance();
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
