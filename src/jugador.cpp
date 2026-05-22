#include "../headers/jugador.hpp"
#include <ostream>
#include <sstream>

std::stringstream Jugador::mostrar_stats() {
  std::stringstream ss;
  ss << "Nombre: " << nombre << std::endl;

  puntaje_total = calc_performance_point();
  ss << "Puntaje total: " << puntaje_total << std::endl;

  return ss;
}

int Jugador::calc_performance_point() {
  // Total pp = p * 0.95^(n-1)
  return 10;
}
