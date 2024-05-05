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
  //// auto name = gui.GetName();
  Player player("SomeName");
  RunGame(player, gui);
  return 0;
}

