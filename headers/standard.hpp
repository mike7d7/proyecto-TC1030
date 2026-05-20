#ifndef STANDARD_H
#define STANDARD_H

#include "partida.hpp"
#include <sstream>

class Standard : public Partida {
private:
  int num_sliders;
  int calc_puntuacion() override;
  int calc_performance() override;
  void calc_accuracy() override;

public:
  void set_num_sliders(int);
  int get_num_sliders();
  void jugar() override;
  std::stringstream mostrar_resultados() override;
};

#endif
