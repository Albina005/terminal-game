#include "player.h"
#include "field.h"
#include "imaging.h"
#include <iostream>
#include <cstdlib>

Player::Player() : name("player"), location(1, 1) {}

Player::Player(int x, int y) : name("player"), location(x, y) {}

Player::Player(std::string name) : name(name), location(1, 1) {}

std::string Player::getName() const {
  return name;
}

int Player::getLives() const {
  return lives;
}

bool Player::getGame() const {
  return game;
}

void Player::setName(std::string new_name) {
  name = new_name;
}

void Player::setLives(int new_lives) {
  lives = new_lives;
}

void Player::setGame(bool new_game) {
  game = new_game;
}


void Player::Move(Direction direction, Field& field, Boundaries& boundaries) {
  int new_x = location.first;
  int new_y = location.second;

  field.visual[location.second][location.first] = "  ";

  if (direction == up) {
    new_y -= 1;  // Go Up
  }
  else if (direction == left) {
    new_x -= 1;  // Go Left
  }
  else if (direction == down) {
    new_y += 1;  // Go Down
  }
  else if (direction == right) {
    new_x += 1;  // Go Right
  }
  else {
    return;
  }
  if (new_x < 0 || new_x >= field.getWidth() || new_y < 0 || new_y >= field.getHeight()) {
    return;
  }

  for (const auto& boundary : boundaries.bound) {
    if (new_x == boundary.first && new_y == boundary.second) {
      if (lives > 0) {
        --lives;
        return;
      }
      else {
        game = false;
        system("cls");
        std::cout << "You lost! \n" << "Your score: " << score << '\n';
        std::system("pause");
        return;
      }
    }
  }

  location.first = new_x;
  location.second = new_y;
  field.visual[location.second][location.first] = "P ";
}

void Player::GetCoin(Field& field) {
  if (score == field.GetNumCoins()) {
    game = false;
    system("cls");
    std::cout << "You win! \n";
    std::system("pause");
    return;
  }
  for (auto it = field.available_coins.begin(); it != field.available_coins.end(); ++it) {
    if (location.second == it->second && location.first == it->first) {
      score += 1;
      it = field.available_coins.erase(it);
      return;
    }
  }
}
