#ifndef PARTIDA_H
#define PARTIDA_H

#include <sstream>
#include <string>

class Partida {
protected:
  std::string beatmap;
  int puntuacion;
  int performance_points;
  double accuracy;
  int num_notas;
  double star_rating;

  int great;
  int ok;
  int meh;
  int miss;
  int max_combo;

  virtual int calc_puntuacion() = 0;
  virtual int calc_performance() = 0;

public:
  Partida() = default;
  virtual ~Partida() = default;
  virtual void jugar() = 0;
  virtual std::stringstream mostrar_resultados() = 0;
};

#endif
