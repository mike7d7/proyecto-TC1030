#include "headers/player.hpp"
#include <iostream>
#include <sstream>

int main() {
  Player player("Test Player");

  // https://osu.ppy.sh/scores/4795773370
  player.new_standard("R U 4 me - Myself", 7.1, 251, 34, 0, 3, 322);
  // https://osu.ppy.sh/scores/1796177590
  player.new_standard("Image material - aimbotcone", 7.57, 1800, 3, 0, 0, 2645);
  // https://osu.ppy.sh/scores/2287924022
  player.new_mania("Galaxy Collapse - DellyK", 8.66, 2666, 89, 10, 84, 2700, 7,
                   5907, 438);
  // https://osu.ppy.sh/scores/6169855412
  player.new_mania("DEUX EX MAXHINA - Gaboelmascapo27", 6.42, 867, 37, 11, 39,
                   291, 4, 1714, 159);
  // https://osu.ppy.sh/scores/6726256610
  player.new_taiko("River of Oblivion - EnigmaticG", 4.89, 1597, 68, 1, 1373);
  // https://osu.ppy.sh/scores/6683345404
  player.new_taiko("River of Oblivion - EnigmaticG", 6.4, 1180, 30, 8, 1057);

  std::stringstream stats = player.show_stats();
  std::stringstream plays = player.show_plays();
  std::cout << stats.str() << std::endl;
  std::cout << plays.str() << std::endl;
}
