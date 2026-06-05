#include "headers/player.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

// Detiene la ejecución hasta que el usuario presiona la tecla "enter".
void enter_to_continue() {
  std::cout << "Presiona enter para continuar" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

// Simula limpiar la pantalla mediante 100 newlines.
void clear() {
  for (int i = 0; i < 100; i++) {
    std::cout << std::endl;
  }
}

void main_menu() {
  clear();
  std::cout << "Ingresa una opción" << std::endl;
  std::cout << "1.- Agregar Jugador" << std::endl;
  std::cout << "2.- Agregar Partida" << std::endl;
  std::cout << "3.- Mostrar estadísticas" << std::endl;
  std::cout << "4.- Salir" << std::endl;
}

// Verifica que el input sea un int válido y que esté dentro del rango
// especificado. Lógica para verificar cast de string a int sacado de:
// https://cplusplus.com/forum/beginner/283248/#msg1226145
int get_int(int min_val, int max_val) {
  int number;
  while (!(std::cin >> number)) {
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
  }
  if (number < min_val || number > max_val) {
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
    number = get_int(min_val, max_val);
  }
  return number;
}

// Verifica que el input sea un double válido y que esté dentro del rango
// especificado. Lógica para verificar cast de string a double sacado de:
// https://cplusplus.com/forum/beginner/283248/#msg1226145
double get_double(double min_val, double max_val) {
  double number;
  while (!(std::cin >> number)) {
    // https://cplusplus.com/forum/beginner/283248/#msg1226145
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
  }
  if (number < min_val || number > max_val) {
    std::cout << "Entrada inválida, intenta otra vez." << std::endl;
    std::cin.clear(); // clear fail flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // discard the whole line
    number = get_double(min_val, max_val);
  }
  return number;
}

void print_players(std::vector<Player> players) {
  for (int i = 0; i < players.size(); i++) {
    std::cout << (i + 1) << ".- " << players[i].get_name() << std::endl;
  }
}

int main() {
  std::vector<Player> players;

  while (true) {
    main_menu();

    int option = get_int(1, 4);

    switch (option) {
    // Add player
    case 1: {
      std::string username;
      std::cout << "Ingresa el nombre de usuario." << std::endl;
      std::cin.ignore();
      getline(std::cin, username);
      players.push_back(Player(username));
      break;
    }
    // Add gamematch
    case 2: {
      clear();

      // Player select
      if (players.size() == 0) {
        std::cout << "Primero registre un jugador." << std::endl;
        enter_to_continue();
        break;
      }
      print_players(players);
      std::cout << "Ingresa el número del jugador correspondiente a la nueva "
                   "partida: ";

      std::cin.ignore();
      int selected_player = get_int(1, players.size()) - 1;
      std::cout << players[selected_player].get_name() << std::endl;

      // Gamemode select
      clear();
      std::cout << "1.- Standard" << std::endl;
      std::cout << "2.- Mania" << std::endl;
      std::cout << "3.- Taiko" << std::endl;
      std::cout << "Ingresa el número del modo de juego de la partida: ";
      int selected_mode = get_int(1, 3);

      std::cout << "Ingresa el nombre de la canción:" << std::endl;
      std::string beatmap;
      std::cin.ignore();
      getline(std::cin, beatmap);

      std::cout << "Ingresa la dificultad en estrellas (0.0 - 15.0):"
                << std::endl;
      double star = get_double(0.0, 15.0);

      std::cout << "Ingresa el número de GREATs:" << std::endl;
      int great = get_int(0, std::numeric_limits<int>::max());

      std::cout << "Ingresa el número de OKs:" << std::endl;
      int ok = get_int(0, std::numeric_limits<int>::max());

      std::cout << "Ingresa el número de MISS:" << std::endl;
      int miss = get_int(0, std::numeric_limits<int>::max());

      switch (selected_mode) {
      case 1: {
        std::cout << "Ingresa el número de MEHs:" << std::endl;
        int meh = get_int(0, std::numeric_limits<int>::max());

        std::cout << "Ingresa el número máximo obtenido de COMBO (Debe ser "
                     "menor o igual al número total de notas):"
                  << std::endl;
        int max_combo = get_int(0, great + ok + meh + miss);

        players[selected_player].new_standard(beatmap, star, great, ok, meh,
                                              miss, max_combo);
        break;
      }
      case 2: {
        std::cout << "Ingresa el número de MEHs:" << std::endl;
        int meh = get_int(0, std::numeric_limits<int>::max());

        std::cout << "Ingresa el número de teclas (4-7):" << std::endl;
        int num_keys = get_int(4, 7);

        std::cout << "Ingresa el número de PERFECTs:" << std::endl;
        int perfect = get_int(0, std::numeric_limits<int>::max());

        std::cout << "Ingresa el número de GOODs:" << std::endl;
        int good = get_int(0, std::numeric_limits<int>::max());

        std::cout << "Ingresa el número máximo obtenido de COMBO:" << std::endl;
        int max_combo = get_int(0, great + ok + meh + miss + perfect + good);

        players[selected_player].new_mania(beatmap, star, great, ok, meh, miss,
                                           max_combo, num_keys, perfect, good);
        break;
      }
      case 3:
        std::cout << "Ingresa el número máximo obtenido de COMBO:" << std::endl;
        int max_combo = get_int(0, great + ok + miss);

        players[selected_player].new_taiko(beatmap, star, great, ok, miss,
                                           max_combo);
        break;
      }
      enter_to_continue();
      break;
    }
    // Show stats
    case 3: {
      // Player select
      if (players.size() == 0) {
        std::cout << "Primero registre un jugador." << std::endl;
        enter_to_continue();
        break;
      }
      print_players(players);
      std::cout << "Ingresa el número del jugador para ver sus estadísticas: ";

      std::cin.ignore();
      int selected_player = get_int(1, players.size()) - 1;
      clear();
      std::cout << players[selected_player].show_stats().str() << std::endl;
      std::cout << players[selected_player].show_plays().str() << std::endl;
      enter_to_continue();
      break;
    }
    // Exit
    case 4:
      return 0;
    }
  }
}
