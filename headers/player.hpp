#ifndef PLAYER_H
#define PLAYER_H

#include "gamematch.hpp"
#include <sstream>
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
  Player(std::string name, std::vector<Gamematch *> vec)
      : name(name), total_score(0), performance_points(0), plays(vec) {};
  std::stringstream show_stats();
};

#endif
