#include "../headers/jugador.hpp"
#include <ostream>
#include <sstream>

std::stringstream Jugador::show_stats() {
  std::stringstream ss;
  ss << "Nombre: " << name << std::endl;

  total_score = calc_performance_point();
  ss << "Puntaje total: " << total_score << std::endl;

  return ss;
}

int Jugador::calc_performance_point() {
  // Total pp = p * 0.95^(n-1)
  return 10;
}
