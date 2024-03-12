#include <iostream>
#include <string>
#include "imaging.cpp"
#include "field.cpp"
#include "player.cpp"
#include <cstdlib>

int main() {
  std::string name;
  std::cout << "Enter name:\n";
  std::cin >> name;

  Player player(name);
  RunGame(player);

  return 0;
}
