#include "player.h"
#include "field.h"
#include <iostream>
#include <cstdlib>

Player::Player() : game(true), name("player"), location(1, 1) {}

Player::Player(int x, int y) : name("player"), location(x, y) {}

Player::Player(std::string name) : name(name), location(1, 1) {}

void Player::Move(char direction, Field& field, Boundaries& boundaries) {
  int new_x = location.first;
  int new_y = location.second;

  field.visual[location.first][location.second] = "  ";

  if (direction == 'w' || direction == 72) {
    new_y -= 1;  // Go Up
  }
  else if (direction == 'a' || direction == 75) {
    new_x -= 1;  // Go Left
  }
  else if (direction == 's' || direction == 80) {
    new_y += 1;  // Go Down
  }
  else if (direction == 'd' || direction == 77) {
    new_x += 1;  // Go Right
  }
  else {
    return;
  }

  bool tr = true;
  if (new_x > 0 && new_x < field.getWidth() && new_y > 0 && new_y < field.getHeight()) {
    for (int i = 0; i < boundaries.GetNum(); ++i) {
      if (new_y == boundaries.bound[i].second && new_x == boundaries.bound[i].first) {
        if (lives > 0) {
          --lives;
          tr = false;
          continue;
        }
        else {
          game = false;
          system("cls");
          std::cout << "You lost! \n" << "Your score: " << score << '\n';
          std::system("pause");
        }
      }
    }

    if (tr) {
      location.first = new_x;
      location.second = new_y;
    }
  }
  field.visual[location.first][location.second] = "P ";
}

void Player::GetCoin(Field& field) {
  if (score == field.num_coins) {
    game = false;
    system("cls");
    std::cout << "You win! \n";
    std::system("pause");
  }
  for (auto it = field.available_coins.begin(); it != field.available_coins.end(); ++it) {
    if (location.second == it->second && location.first == it->first) {
      score += 1;
      field.available_coins.erase(it);
      return;
    }
  }
}
