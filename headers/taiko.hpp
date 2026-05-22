#ifndef TAIKO_H
#define TAIKO_H

#include "partida.hpp"

class Taiko : public Partida {
private:
  int calc_puntuacion() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  void jugar() override;
  std::stringstream mostrar_resultados() override;
  Taiko() : Partida("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};
  Taiko(std::string bm, double star, int great, int ok, int miss, int max_combo)
      : Partida(bm, star, great, ok, 0, miss, max_combo, 0, 0, 0, 0) {};
};

#endif
