#include "../headers/player.hpp"
#include "../headers/mania.hpp"
#include "../headers/standard.hpp"
#include "../headers/taiko.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

// Regresa stringstream con estadísticas del jugador para mostrarlas en output
std::stringstream Player::show_stats() {
  std::stringstream ss;
  ss << "Nombre: " << name << std::endl;

  performance_points = calc_performance_point();
  ss << "Puntos de rendimiento: " << performance_points << std::endl;

  total_score = 0;
  for (auto i : plays) {
    total_score += i->get_score();
  }
  ss << "Puntaje total: " << total_score << std::endl;
  return ss;
}

// Regresa stringstream con la info de cada partida del jugador
std::stringstream Player::show_plays() {
  std::stringstream ss;
  for (auto i : plays) {
    i->play();
    ss << i->show_results().str() << std::endl;
  }

  return ss;
}

// Calcula los puntos de rendimiento de cada partida individual y usa la fórmula
// de ponderación para obtener los puntos de rendimiento del jugador
// Regresa:
//      Puntos de rendimiento de jugador
int Player::calc_performance_point() {
  for (auto i : plays) {
    i->play();
  }
  // https://stackoverflow.com/questions/1380463/how-do-i-sort-a-vector-of-custom-objects
  std::sort(plays.begin(), plays.end(), [](Gamematch *a, Gamematch *b) {
    return a->get_performance_points() > b->get_performance_points();
  });

  // Total pp = p * 0.95^(n-1)
  int pp = 0;
  for (int i = 0; i < plays.size(); i++) {
    pp += plays[i]->get_performance_points() * std::pow(0.95, i);
  }

  return pp;
}

// Pasa parámetros al constructor para crear nueva partida (tipo standard) y
// agregarla al vector
// Recibe:
//      Nombre del mapa
//      Dificultad en estrellas
//      Cantidad de notas con precisión great
//      Cantidad de notas con precisión ok
//      Cantidad de notas con precisión meh
//      Cantidad de notas falladas
//      Combo máximo
void Player::new_standard(std::string bm, double star, int great, int ok,
                          int meh, int miss, int max_combo) {
  Gamematch *match = new Standard(bm, star, great, ok, meh, miss, max_combo);
  plays.push_back(match);
};

// Pasa parámetros al constructor para crear nueva partida (tipo mania) y
// agregarla al vector
// Recibe:
//      Nombre del mapa
//      Dificultad en estrellas
//      Cantidad de notas con precisión great
//      Cantidad de notas con precisión ok
//      Cantidad de notas con precisión meh
//      Cantidad de notas falladas
//      Combo máximo
//      Número de teclas (4-7) con las que se juega el mapa
//      Cantidad de notas con precisión perfect
//      Cantidad de notas con precisión good
void Player::new_mania(std::string bm, double star, int great, int ok, int meh,
                       int miss, int max_combo, int num_keys, int perfect,
                       int good) {
  Gamematch *match = new Mania(bm, star, great, ok, meh, miss, max_combo,
                               num_keys, perfect, good);
  plays.push_back(match);
};

// Pasa parámetros al constructor para crear nueva partida (tipo taiko) y
// agregarla al vector
// Recibe:
//      Nombre del mapa
//      Dificultad en estrellas
//      Cantidad de notas con precisión great
//      Cantidad de notas con precisión ok
//      Cantidad de notas falladas
//      Combo máximo
void Player::new_taiko(std::string bm, double star, int great, int ok, int miss,
                       int max_combo) {
  Gamematch *match = new Taiko(bm, star, great, ok, miss, max_combo);
  plays.push_back(match);
};

// Getter
std::string Player::get_name() { return name; }
