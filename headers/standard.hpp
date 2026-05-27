#ifndef STANDARD_H
#define STANDARD_H

#include "gamematch.hpp"
#include <sstream>
#include <string>

class Standard : public Gamematch {
private:
  int calc_score() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  void play() override;
  std::stringstream show_results() override;
  Standard() : Gamematch("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};
  Standard(std::string bm, double star, int great, int ok, int meh, int miss,
           int max_combo)
      : Gamematch(bm, star, great, ok, meh, miss, max_combo, 0, 0, 0, 0) {};
};

#endif
