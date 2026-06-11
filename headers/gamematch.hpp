#ifndef GAMEMATCH_H
#define GAMEMATCH_H

#include <sstream>
#include <string>

class Gamematch {
protected:
  // Datos de las canciones
  std::string beatmap;
  int num_notes;
  double star_rating;

  // Datos después de jugar
  int score;
  int performance_points;
  double accuracy;

  // Datos para juzgar partidas (en todos los modos)
  int great;
  int ok;
  int meh;
  int miss;
  int max_combo;

  // Métodos para calcular datos de juego
  virtual int calc_score() = 0;
  virtual int calc_performance() = 0;
  virtual double calc_accuracy() = 0;

public:
  // Constructor default
  Gamematch() = default;

  // Constructor con parámetros, recibe todos las variables de la clase
  Gamematch(std::string bm, double star, int great, int ok, int meh, int miss,
            int max_combo, int score, int perf, double acc, int num_notes)
      : beatmap(bm), star_rating(star), great(great), ok(ok), meh(meh),
        miss(miss), max_combo(max_combo), score(score),
        performance_points(perf), accuracy(acc), num_notes(num_notes) {};

  // Destructor default
  virtual ~Gamematch() = default;

  // Simula la partida y calcula los datos de juego (depende del modo)
  virtual void play() = 0;

  // Muestra los datos de una partida (depende del modo)
  virtual std::stringstream show_results() = 0;

  // Getters
  int get_performance_points();
  int get_score();
};

#endif
