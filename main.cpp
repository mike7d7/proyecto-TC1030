#include "headers/mania.hpp"
#include "headers/standard.hpp"
#include "headers/taiko.hpp"
#include <iostream>
#include <sstream>

int main() {
  Standard play1;
  // play1.set_num_sliders(350);
  play1.jugar();
  std::stringstream ss = play1.mostrar_resultados();

  std::cout << ss.str() << std::endl;

  Mania mania_test;
  mania_test.jugar();
  std::stringstream ss2 = mania_test.mostrar_resultados();
  std::cout << ss2.str() << std::endl;

  Taiko taiko_test;
  taiko_test.jugar();
  std::stringstream ss3 = taiko_test.mostrar_resultados();
  std::cout << ss3.str() << std::endl;
}
