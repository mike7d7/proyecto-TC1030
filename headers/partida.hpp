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
  virtual double calc_accuracy() = 0;

public:
  Partida() = default;
  Partida(std::string bm, double star, int great, int ok, int meh, int miss,
          int max_combo, int punt, int perf, double acc, int num_notas)
      : beatmap(bm), star_rating(star), great(great), ok(ok), meh(meh),
        miss(miss), max_combo(max_combo), puntuacion(punt),
        performance_points(perf), accuracy(acc), num_notas(num_notas) {};
  virtual ~Partida() = default;
  virtual void jugar() = 0;
  virtual std::stringstream mostrar_resultados() = 0;
};

#endif
