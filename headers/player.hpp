#ifndef PLAYER_H
#define PLAYER_H

#include "gamematch.hpp"
#include <string>
#include <vector>

class Player {
private:
  // Estadísticas del jugador
  std::string name;
  int total_score;
  int performance_points;

  // Vector con las partidas del jugador (independiente del modo)
  std::vector<Gamematch *> plays;

  // Calcular los puntos de rendimiento totales del jugador
  int calc_performance_point();

public:
  // Constructor default
  Player();

  // Constructor con parámetros, recibe el nombre, define las estadísticas como
  // 0
  Player(std::string name)
      : name(name), total_score(0), performance_points(0) {};

  // Muestra las estadísticas
  std::stringstream show_stats();

  // Muestra la info de cada partida del jugaador
  std::stringstream show_plays();

  // Crea nueva partida de tipo standard y la agrega al vector
  void new_standard(std::string bm, double star, int great, int ok, int meh,
                    int miss, int max_combo);

  // Crea nueva partida de tipo mania y la agrega al vector
  void new_mania(std::string bm, double star, int great, int ok, int meh,
                 int miss, int max_combo, int num_keys, int perfect, int good);

  // Crea nueva partida de tipo taiko y la agrega al vector
  void new_taiko(std::string bm, double star, int great, int ok, int miss,
                 int max_combo);

  // Getter
  std::string get_name();
};

#endif
