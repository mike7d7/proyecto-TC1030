#ifndef STANDARD_H
#define STANDARD_H

#include "partida.hpp"
#include <sstream>

class Standard : public Partida {
private:
  int calc_puntuacion() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  void jugar() override;
  std::stringstream mostrar_resultados() override;
};

#endif
