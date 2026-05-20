#include "headers/standard.hpp"
#include <iostream>
#include <sstream>

int main() {
  Standard play1;
  // play1.set_num_sliders(350);
  play1.jugar();
  std::stringstream ss = play1.mostrar_resultados();

  std::cout << ss.str() << std::endl;
}
