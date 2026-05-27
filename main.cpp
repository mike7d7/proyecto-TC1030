#include "headers/mania.hpp"
#include "headers/player.hpp"
#include "headers/standard.hpp"
#include "headers/taiko.hpp"
#include <iostream>

int main() {
  // https://osu.ppy.sh/scores/4795773370
  Standard *std1 = new Standard("R U 4 me - Myself", 7.1, 251, 34, 0, 3, 322);
  // https://osu.ppy.sh/scores/1796177590
  Standard *std2 =
      new Standard("Image material - aimbotcone", 7.57, 1800, 3, 0, 0, 2645);

  // https://osu.ppy.sh/scores/2287924022
  Mania *mania1 = new Mania("Galaxy Collapse - DellyK", 8.66, 2666, 89, 10, 84,
                            2700, 7, 5907, 438);
  // https://osu.ppy.sh/scores/6169855412
  Mania *mania2 = new Mania("DEUX EX MAXHINA - Gaboelmascapo27", 6.42, 867, 37,
                            11, 39, 291, 4, 1714, 159);

  // https://osu.ppy.sh/scores/6726256610
  Taiko *taiko1 =
      new Taiko("River of Oblivion - EnigmaticG", 4.89, 1597, 68, 1, 1373);
  // https://osu.ppy.sh/scores/6683345404
  Taiko *taiko2 =
      new Taiko("River of Oblivion - EnigmaticG", 6.4, 1180, 30, 8, 1057);

  std::vector<Gamematch *> partidas;

  partidas.push_back(std1);
  partidas.push_back(std2);
  partidas.push_back(mania1);
  partidas.push_back(mania2);
  partidas.push_back(taiko1);
  partidas.push_back(taiko2);

  for (auto i : partidas) {
    i->play();
    std::cout << i->show_results().str() << std::endl;
  }

  Player player("Test Player", partidas);
  std::stringstream stats = player.show_stats();
  std::cout << stats.str() << std::endl;
}
