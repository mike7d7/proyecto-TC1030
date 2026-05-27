#ifndef JUGADOR_H
#define JUGADOR_H

#include "partida.hpp"
#include <sstream>
#include <string>
#include <vector>

class Jugador {
private:
  std::string name;
  int total_score;
  int performance_points;

  std::vector<Partida *> plays;

  int calc_performance_point();

public:
  Jugador();
  Jugador(std::string name, std::vector<Partida *> vec)
      : name(name), total_score(0), performance_points(0), plays(vec) {};
  std::stringstream show_stats();
};

#endif
