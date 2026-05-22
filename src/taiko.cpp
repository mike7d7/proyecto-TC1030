#include "../headers/taiko.hpp"
#include <cmath>

double Taiko::calc_accuracy() {
  double acc = (great + 0.5 * ok) / num_notas;
  return acc;
}

void Taiko::jugar() {
  num_notas = great + ok + miss;

  accuracy = calc_accuracy();
  puntuacion = calc_puntuacion();
  performance_points = calc_performance();
};

int Taiko::calc_puntuacion() {
  int punt = 1000000 * (0.7 * sqrt((double)max_combo / num_notas) +
                        0.3 * std::pow(accuracy, 10));
  return punt;
};

int Taiko::calc_performance() {
  int perf = 12 * std::pow(star_rating, 2.2) * std::pow(accuracy, 6) *
             std::pow(0.97, miss) * sqrt((double)max_combo / num_notas);
  return perf;
};

std::stringstream Taiko::mostrar_resultados() {
  std::stringstream ss;
  ss << "█████ " << beatmap << " █████" << std::endl;
  ss << "Modo: Taiko" << std::endl;
  ss << "Número de notas: " << num_notas << std::endl;
  ss << "Accuracy: " << accuracy << std::endl;
  ss << "Puntuación: " << puntuacion << std::endl;
  ss << "Puntos de rendimiento: " << performance_points << std::endl;
  return ss;
}
