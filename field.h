#ifndef FIELDH
#define FIELDH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include "player.h"

class Player;
class Boundaries;

class Field {
private:
  const int width = 20;
  const int height = 20;

public:
  const int num_coins = 15;
  std::vector<std::vector<std::string>> visual;
  std::vector<std::pair<int, int>> available_coins;

  Field() {
    visual.resize(height + 2, std::vector<std::string>(width + 2, "  "));
    for (int i = 0; i <= height + 1; ++i) {
      for (int j = 0; j <= width + 1; ++j) {
        if (i == 0 || i == height || j == 0 || j == width) {
          visual[i][j] = "# ";
        }
      }
    }

    SetCoins();
  }

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void SetCoins() {
    for (int i = 0; i < num_coins; ++i) {
      int x = rand() % (width - 2) + 1;
      int y = rand() % (height - 2) + 1;
      available_coins.push_back(std::make_pair(x, y));
      visual[x][y] = "0 ";
    }
  }
};

bool Compare(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
  if (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first)) {
    return true;
  }
  return false;
}

class Boundaries {
private:
  const int num = 30;

public:
  int GetNum() { return num; }
  std::vector<std::pair<int, int>> bound;
  Boundaries(Field& field) {
    for (int i = 0; i < num; ++i) {
      bool tr = true;
      int x = rand() % (field.getWidth() - 2) + 1;
      int y = rand() % (field.getHeight() - 2) + 1;
      for (int j = 0; j < field.num_coins; ++j) {
        if (y == field.available_coins[j].second && field.available_coins[j].first == x) {
          tr = false;
          break;
        }
      }
      if (tr) {
        bound.push_back(std::make_pair(x, y));
      }
      else {
        bound.push_back(std::make_pair(0, 0));
      }
    }
    std::sort(bound.begin(), bound.end(), Compare);
  }

  void SetBoundaries(Field& field) {
    for (int i = 0; i < num; ++i) {
      field.visual[bound[i].first][bound[i].second] = "# ";
    }
  }
};

#endif
