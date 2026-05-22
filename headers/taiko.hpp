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
};

#endif
