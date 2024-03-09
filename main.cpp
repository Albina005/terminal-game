#include <iostream>
#include <string>
#include "pacman.h"
#include "field.h"
#include "player.h"

class Player;

int main() {
  std::string name;
  std::cout << "Enter name \n";
  std::cin >> name;
  Player player(name);
  RunGame(player);
  return 0;
}
