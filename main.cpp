#include <iostream>
#include <string>
#include <cstdlib>
class Field;
class Game;
#include "field.cpp"
#include "player.cpp"
#include "imaging.cpp"

#include <cstdlib>

int main() {
  std::string name;
  std::cout << "Enter name:\n";
  std::cin >> name;

  Player player(name);
  RunGame(player);

  return 0;
}
