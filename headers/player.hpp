#ifndef PLAYER_H
#define PLAYER_H

#include "gamematch.hpp"
#include <string>
#include <vector>

class Player {
private:
  std::string name;
  int total_score;
  int performance_points;

  std::vector<Gamematch *> plays;

  int calc_performance_point();

public:
  Player();
  Player(std::string name)
      : name(name), total_score(0), performance_points(0) {};

  std::stringstream show_stats();
  std::stringstream show_plays();

  void new_standard(std::string bm, double star, int great, int ok, int meh,
                    int miss, int max_combo);
  void new_mania(std::string bm, double star, int great, int ok, int meh,
                 int miss, int max_combo, int num_keys, int perfect, int good);
  void new_taiko(std::string bm, double star, int great, int ok, int miss,
                 int max_combo);
  std::string get_name();
};

#endif
