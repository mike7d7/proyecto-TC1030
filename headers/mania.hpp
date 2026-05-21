#ifndef MANIA_H
#define MANIA_H

#include "../headers/partida.hpp"

class Mania : public Partida {
private:
  int num_teclas;
  int perfect;
  int good;

  int calc_puntuacion() override;
  int calc_performance() override;
  void calc_accuracy() override;

public:
  int get_num_teclas();
  void set_num_teclas(int);

  void jugar() override;
  std::stringstream mostrar_resultados() override;
};

#endif
