#ifndef MANIA_H
#define MANIA_H

#include "gamematch.hpp"

class Mania : public Gamematch {
private:
  // Datos de canciones (exclusivos de mania)
  int num_keys;
  int perfect;
  int good;

  // Métodos para calcular datos de juego (sobreescritura)
  int calc_score() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  // Getters y setters
  int get_num_keys();
  void set_num_keys(int);

  // Simular partida
  void play() override;

  // Regresar datos importantes (sobreescritura)
  std::stringstream show_results() override;

  // Constructor default
  Mania()
      : Gamematch("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), num_keys(0), perfect(0),
        good(0) {};

  // Constructor con parámetros (inputs del usuario siempre usan constructor con
  // parámetros)
  // Valores en 0 serán calculados por métodos
  Mania(std::string bm, double star, int great, int ok, int meh, int miss,
        int max_combo, int num_keys, int perfect, int good)
      : Gamematch(bm, star, great, ok, meh, miss, max_combo, 0, 0, 0, 0),
        num_keys(num_keys), perfect(perfect), good(good) {};
};

#endif
