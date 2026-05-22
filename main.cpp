#include "headers/mania.hpp"
#include "headers/standard.hpp"
#include "headers/taiko.hpp"
#include <iostream>
#include <sstream>

int main() {
  // https://osu.ppy.sh/scores/4795773370
  Standard play1("R U 4 me - Myself", 7.1, 251, 34, 0, 3, 322);
  // https://osu.ppy.sh/scores/1796177590
  // Standard play1("Image material - aimbotcone", 7.57, 1800, 3, 0, 0, 2645);
  play1.jugar();
  std::stringstream ss = play1.mostrar_resultados();
  std::cout << ss.str() << std::endl;

  // https://osu.ppy.sh/scores/2287924022
  Mania mania_test("Galaxy Collapse - DellyK", 8.66, 2666, 89, 10, 84, 2700, 7,
                   5907, 438);
  // https://osu.ppy.sh/scores/6169855412
  // Mania mania_test("DEUX EX MAXHINA - Gaboelmascapo27", 6.42, 867, 37, 11,
  // 39,
  //                  291, 4, 1714, 159);
  mania_test.jugar();
  std::stringstream ss2 = mania_test.mostrar_resultados();
  std::cout << ss2.str() << std::endl;

  Taiko taiko_test;
  taiko_test.jugar();
  std::stringstream ss3 = taiko_test.mostrar_resultados();
  std::cout << ss3.str() << std::endl;
}
