#ifndef TAIKO_H
#define TAIKO_H

#include "gamematch.hpp"

class Taiko : public Gamematch {
private:
  int calc_score() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  void play() override;
  std::stringstream show_results() override;
  Taiko() : Gamematch("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};
  Taiko(std::string bm, double star, int great, int ok, int miss, int max_combo)
      : Gamematch(bm, star, great, ok, 0, miss, max_combo, 0, 0, 0, 0) {};
};

#endif
