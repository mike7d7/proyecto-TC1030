#include "../headers/mania.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

int Mania::get_num_teclas() { return num_teclas; }
void Mania::set_num_teclas(int num) { num_teclas = num; }

double Mania::calc_accuracy() {
  // https://osu.ppy.sh/wiki/en/Gameplay/Accuracy#osu%21mania (v2)
  int perfect_score = 305 * num_notas;
  int real =
      305 * perfect + 300 * great + (200 * good) + (100 * ok) + (50 * meh);
  double acc = (double)real / perfect_score;
  return acc;
}
void Mania::jugar() {
  // https://osu.ppy.sh/scores/2287924022
  // perfect = 5907;
  // great = 2666;
  // good = 438;
  // ok = 89;
  // meh = 10;
  // miss = 84;
  // max_combo = 2700;
  // star_rating = 8.66;
  // num_teclas = 7;

  // https://osu.ppy.sh/scores/6169855412
  perfect = 1714;
  great = 867;
  good = 159;
  ok = 37;
  meh = 11;
  miss = 39;
  max_combo = 291;
  star_rating = 6.42;
  num_teclas = 4;

  num_notas = perfect + great + good + ok + meh + miss;

  accuracy = calc_accuracy();
  puntuacion = calc_puntuacion();
  performance_points = calc_performance();
};
int Mania::calc_puntuacion() {

  double combo_factor = log(1.0 + max_combo) / log(1.0 + num_notas);

  int score = 1000000 * (0.3 * pow(accuracy, 5) + 0.7 * combo_factor);
  return score;
};
int Mania::calc_performance() {
  int perf = 1000 * std::pow(star_rating / 10, 1.6) *
             (0.65 * std::pow(accuracy, 5.5) +
              0.35 * std::pow((double)max_combo / num_notas, 0.3)) *
             (1 + 0.08 * ((num_teclas - 4) / 4.0));
  return perf;
};

std::stringstream Mania::mostrar_resultados() {
  std::stringstream ss;
  ss << "Número de notas: " << num_notas << std::endl;
  ss << "Accuracy: " << accuracy << std::endl;
  ss << "Puntuación: " << puntuacion << std::endl;
  ss << "Puntos de rendimiento: " << performance_points << std::endl;
  return ss;
}
