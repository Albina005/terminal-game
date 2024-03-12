#include "field.h"


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
    bool tr = true;
    int x, y;
    do {
      x = rand() % (field.getWidth() - 2) + 1;
      y = rand() % (field.getHeight() - 2) + 1;

      for (const auto& coin : field.available_coins) {
        if (coin.first == x && coin.second == y) {
          tr = false;
          break;
        }
      }
    } while (!tr);

    bound.push_back(std::make_pair(x, y));
  }
  std::sort(bound.begin(), bound.end(), Compare);
}

void Boundaries::SetBoundaries(Field& field) {
  for (const auto& boundPoint : bound) {
    field.visual[boundPoint.second][boundPoint.first] = "# ";
  }
}
