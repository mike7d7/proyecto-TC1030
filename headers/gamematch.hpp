#ifndef GAMEMATCH_H
#define GAMEMATCH_H

#include <sstream>
#include <string>

class Gamematch {
protected:
  std::string beatmap;
  int score;
  int performance_points;
  double accuracy;
  int num_notes;
  double star_rating;

  int great;
  int ok;
  int meh;
  int miss;
  int max_combo;

  virtual int calc_score() = 0;
  virtual int calc_performance() = 0;
  virtual double calc_accuracy() = 0;

public:
  Gamematch() = default;
  Gamematch(std::string bm, double star, int great, int ok, int meh, int miss,
            int max_combo, int score, int perf, double acc, int num_notes)
      : beatmap(bm), star_rating(star), great(great), ok(ok), meh(meh),
        miss(miss), max_combo(max_combo), score(score),
        performance_points(perf), accuracy(acc), num_notes(num_notes) {};
  virtual ~Gamematch() = default;
  virtual void play() = 0;
  virtual std::stringstream show_results() = 0;
  int get_performance_points();
};

#endif
