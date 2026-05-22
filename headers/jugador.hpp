#ifndef JUGADOR_H
#define JUGADOR_H

#include "partida.hpp"
#include <sstream>
#include <string>
#include <vector>

class Jugador {
private:
  std::string nombre;
  int puntaje_total;
  int performance_points;

  std::vector<Partida *> partidas;

  int calc_performance_point();

public:
  Jugador();
  Jugador(std::string nom, std::vector<Partida *> vec)
      : nombre(nom), puntaje_total(0), performance_points(0), partidas(vec) {};
  std::stringstream mostrar_stats();
};

#endif
