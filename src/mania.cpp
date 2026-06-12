#include "../headers/mania.hpp"
#include <cmath>

// Getters y setters
int Mania::get_num_keys() { return num_keys; }
void Mania::set_num_keys(int num) { num_keys = num; }

// Caclular el accuracy de la partida utilizando las distintas precisiones.
// Regresa:
//      La precisión (accuracy) de la partida
double Mania::calc_accuracy() {
  // https://osu.ppy.sh/wiki/en/Gameplay/Accuracy#osu%21mania (v2)
  int perfect_score = 305 * num_notes;
  int real =
      305 * perfect + 300 * great + (200 * good) + (100 * ok) + (50 * meh);
  double acc = (double)real / perfect_score;
  return acc;
}

// Calcular la puntuación (normalizada a max. 1000000).
// Regresa:
//      La puntuación de la partida
int Mania::calc_score() {
  // Importancia del combo en la puntuación
  double combo_factor = log(1.0 + max_combo) / log(1.0 + num_notes);

  int score = 1000000 * (0.3 * pow(accuracy, 5) + 0.7 * combo_factor);
  return score;
};

// Calcular los puntos de rendimiento.
// Regresa:
//      Los puntos de rendimiento de la partida
int Mania::calc_performance() {
  int perf = 1000 * std::pow(star_rating / 10, 1.6) *
             (0.65 * std::pow(accuracy, 5.5) +
              0.35 * std::pow((double)max_combo / num_notes, 0.3)) *
             (1 + 0.08 * ((num_keys - 4) / 4.0));
  return perf;
};

// Simular el juego de una partida
// Utiliza las 3 funciones de calc_*() en un orden específico para evitar
// errores.
void Mania::play() {
  num_notes = perfect + great + good + ok + meh + miss;

  accuracy = calc_accuracy();
  score = calc_score();
  performance_points = calc_performance();
};

// Regresa stringstream con los datos importantes para mostrarlos después.
std::stringstream Mania::show_results() {
  std::stringstream ss;
  ss << "█████ " << beatmap << " █████" << std::endl;
  ss << "Modo: Mania" << std::endl;
  ss << "Número de notas: " << num_notes << std::endl;
  ss << "Número de teclas: " << num_keys << "K" << std::endl;
  ss << "Accuracy: " << accuracy << std::endl;
  ss << "Puntuación: " << score << std::endl;
  ss << "Puntos de rendimiento: " << performance_points << std::endl;
  return ss;
}
