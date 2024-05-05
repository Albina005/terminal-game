#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include <ncurses.h>
class Field;
class Game;
#include "field.cpp"
#include "player.cpp"
#include "imaging.cpp"
#include "gui.cpp"
#include "ghost.cpp"


int main() {
  Gui gui;
  std::cout << "Smp";
  //// auto name = gui.GetName();
  Player player("SomeName");
  std::cout << "Smp";
  RunGame(player, gui);
  return 0;
}

