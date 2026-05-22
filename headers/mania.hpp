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
  double calc_accuracy() override;

public:
  int get_num_teclas();
  void set_num_teclas(int);

  void jugar() override;
  std::stringstream mostrar_resultados() override;
  Mania() : Partida("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};
  Mania(std::string bm, double star, int great, int ok, int meh, int miss,
        int max_combo, int num_teclas, int perfect, int good)
      : Partida(bm, star, great, ok, meh, miss, max_combo, 0, 0, 0, 0),
        num_teclas(num_teclas), perfect(perfect), good(good) {};
};

#endif
