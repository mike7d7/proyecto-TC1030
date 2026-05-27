#include "../headers/player.hpp"

std::stringstream Player::show_stats() {
  std::stringstream ss;
  ss << "Nombre: " << name << std::endl;

  total_score = calc_performance_point();
  ss << "Puntaje total: " << total_score << std::endl;

  return ss;
}

int Player::calc_performance_point() {
  // Total pp = p * 0.95^(n-1)
  return 10;
}
