#ifndef PLAYERH
#define PLAYERH

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>

enum Direction {
  up,
  down,
  left,
  right,
  undefined
};

class Field;
class Boundaries;


class Player {
  std::string name;
  int lives = 5;
  bool game = true;
public:
  int64_t score = 0;
  std::pair<int, int> location;

  Player();
  Player(int x, int y);
  Player(std::string name);
  std::string getName() const;
  int getLives() const;
  bool getGame() const;
  void setName(std::string new_name);
  void setLives(int new_lives);
  void setGame(bool new_game);

  void Move(Direction direction, Field& field, Boundaries& boundaries);
  void GetCoin(Field& field);
};

#endif
