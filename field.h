#ifndef FIELDH
#define FIELDH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

class Field {
  const int width = 20;
  const int height = 20;
  const int num_coins = 15;
public:
  std::vector<std::vector<std::string>> visual;
  std::vector<std::pair<int, int>> available_coins;
  Field();



  int getWidth() const;
  int getHeight() const;
  int GetNumCoins() const;
  void SetCoins();
};

class Boundaries {
private:
  const int num = 30;

public:
  int GetNum();
  std::vector<std::pair<int, int>> bound;
  Boundaries(Field& field);

  void SetBoundaries(Field& field);
};

bool Compare(const std::pair<int, int>& p1, const std::pair<int, int>& p2);

#endif
