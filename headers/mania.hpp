#ifndef MANIA_H
#define MANIA_H

#include "gamematch.hpp"

class Mania : public Gamematch {
private:
  int num_keys;
  int perfect;
  int good;

  int calc_score() override;
  int calc_performance() override;
  double calc_accuracy() override;

public:
  int get_num_keys();
  void set_num_keys(int);

  void play() override;
  std::stringstream show_results() override;
  Mania() : Gamematch("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {};
  Mania(std::string bm, double star, int great, int ok, int meh, int miss,
        int max_combo, int num_keys, int perfect, int good)
      : Gamematch(bm, star, great, ok, meh, miss, max_combo, 0, 0, 0, 0),
        num_keys(num_keys), perfect(perfect), good(good) {};
};

#endif
