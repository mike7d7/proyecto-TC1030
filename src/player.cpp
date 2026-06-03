#include "../headers/player.hpp"
#include "../headers/mania.hpp"
#include "../headers/standard.hpp"
#include "../headers/taiko.hpp"
#include <sstream>
#include <string>

std::stringstream Player::show_stats() {
  std::stringstream ss;
  ss << "Nombre: " << name << std::endl;

  total_score = calc_performance_point();
  ss << "Puntaje total: " << total_score << std::endl;
  return ss;
}

std::stringstream Player::show_plays() {
  std::stringstream ss;
  for (auto i : plays) {
    i->play();
    ss << i->show_results().str() << std::endl;
  }

  return ss;
}

int Player::calc_performance_point() {
  // Total pp = p * 0.95^(n-1)
  return 10;
}

void Player::new_standard(std::string bm, double star, int great, int ok,
                          int meh, int miss, int max_combo) {
  Gamematch *match = new Standard(bm, star, great, ok, meh, miss, max_combo);
  plays.push_back(match);
};

void Player::new_mania(std::string bm, double star, int great, int ok, int meh,
                       int miss, int max_combo, int num_keys, int perfect,
                       int good) {
  Gamematch *match = new Mania(bm, star, great, ok, meh, miss, max_combo,
                               num_keys, perfect, good);
  plays.push_back(match);
};

void Player::new_taiko(std::string bm, double star, int great, int ok, int miss,
                       int max_combo) {
  Gamematch *match = new Taiko(bm, star, great, ok, miss, max_combo);
  plays.push_back(match);
};

std::string Player::get_name() { return name; }
