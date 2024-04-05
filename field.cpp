#include "field.h"
#include "player.h"
#include "imaging.h"
#include "gui.h"

int Field::getWidth() const {
  return width;
}

int Field::getHeight() const {
  return height;
}

int Field::GetNumCoins() const {
  return num_coins;
}

Field::Field() {
  visual.resize(height + 1, std::vector<std::string>(width + 1));
  SetCoins();
}

void Field::SetCoins() {
  for (int i = 0; i < num_coins; ++i) {
    int x = rand() % (width - 2) + 1;
    int y = rand() % (height - 2) + 1;
    available_coins.push_back(std::make_pair(x, y));
    visual[y][x] = "0 ";
  }
}

bool Compare(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
  if (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first)) {
    return true;
  }
  return false;
}

int Boundaries::GetNum() {
  return num;
}

Boundaries::Boundaries(Field& field) {
  for (int i = 0; i < num; ++i) {
    bool is_valid = false;
    int x, y;
    do {
      x = rand() % (field.getWidth() - 2) + 1;
      y = rand() % (field.getHeight() - 2) + 1;

      is_valid = true;

      for (const auto& coin : field.available_coins) {
        if (coin.first == x && coin.second == y) {
          is_valid = false;
          break;
        }
      }

    } while (!is_valid);

    bound.push_back(std::make_pair(x, y));
  }
}

void Boundaries::SetBoundaries(Field& field) {
  for (int i = 0; i < num; ++i) {
    field.visual[bound[i].second][bound[i].first] = "# ";
  }

  // Установка границ по всем сторонам поля
  for (int i = 0; i < field.getWidth(); ++i) {
    field.visual[0][i] = "# ";
    field.visual[field.getHeight() - 1][i] = "# ";
  }
  for (int i = 0; i < field.getHeight(); ++i) {
    field.visual[i][0] = "# ";
    field.visual[i][field.getWidth() - 1] = "# ";
  }
}

