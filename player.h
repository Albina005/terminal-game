#ifndef PLAYERH
#define PLAYERH

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>

#include "field.h"
class Field;
class Boundaries;

class Player {
public:
  std::string name;
  int lives = 5;
  int64_t score = 0;
  std::pair<int, int> location;
  bool game;

  Player();
  Player(int x, int y);
  Player(std::string name);

  void Move(char direction, Field& field, Boundaries& boundaries);
  void GetCoin(Field& field);
};

#endif
