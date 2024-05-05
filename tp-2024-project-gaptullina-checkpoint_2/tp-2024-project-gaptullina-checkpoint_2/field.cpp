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

void Field::SetField(Player& player, Ghost& ghost, Boundaries& bound) {
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) { // Опечатка: wight -> width
      if (i == player.location.first && j == player.location.second) { // Опечатка: одинарное = вместо ==
        visual[i][j] = "p ";
      }
      else if (std::find(available_coins.begin(), available_coins.end(), std::make_pair(i, j)) != available_coins.end()) { // Использование std::find для поиска пары координат
        visual[i][j] = "0 ";
      }
      else if (std::find(bound.bound.begin(), bound.bound.end(), std::make_pair(i, j)) != bound.bound.end()) { // Использование std::find для поиска пары координат, bound.bound для доступа к вектору границ
        visual[i][j] = "# ";
      }
      else {
        visual[i][j] = ". ";
      }
      if (ghost.location.first == i && ghost.location.second == j) { // Опечатка: пропущено ==
        visual[i][j] = "g ";
      }
    }
  }
}


void Field::SetCoins() {
  for (int i = 0; i < num_coins; ++i) {
    int x = rand() % (width - 2) + 1;
    int y = rand() % (height - 2) + 1;
    available_coins.push_back(std::make_pair(x, y));
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
  for (int i = 0; i < field.getWidth(); ++i) {
    bound.push_back(std::make_pair(i, 0));
  }
  for (int i = 0; i < field.getWidth(); ++i) {
    bound.push_back(std::make_pair(i, field.getHeight() - 1));
  }
  for (int i = 1; i < field.getHeight() - 1; ++i) {
    bound.push_back(std::make_pair(0, i));
  }
  for (int i = 1; i < field.getHeight() - 1; ++i) {
    bound.push_back(std::make_pair(field.getWidth() - 1, i));
  }

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

