#ifndef TAIKO_H
#define TAIKO_H

#include "gamematch.hpp"

class Taiko : public Gamematch {
private:
  // Métodos para calcular datos de juego (sobreescritura)
  int calc_score() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  // Simular partida
  void play() override;

  // Regresar datos importantes (sobreescritura)
  std::stringstream show_results() override;

  // Constructor default
  Taiko() : Gamematch("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};

  // Constructor con parámetros (inputs del usuario siempre usan constructor con
  // parámetros)
  // Valores en 0 serán calculados por métodos
  Taiko(std::string bm, double star, int great, int ok, int miss, int max_combo)
      : Gamematch(bm, star, great, ok, 0, miss, max_combo, 0, 0, 0, 0) {};
};

#endif
