#include "player.h"
#include "field.h"
#include "imaging.h"
#include "gui.h"

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

void Player::Move(Gui& gui, Direction direction, Field& field, Boundaries& boundaries) {
  sf::RenderWindow& window = gui.GetWindow();
  int new_x = location.first;
  int new_y = location.second;

  field.visual[location.second][location.first] = "  ";

  if (direction == Direction::up) {
    new_y -= 1;  // Go Up
  }
  else if (direction == Direction::left) {
    new_x -= 1;  // Go Left
  }
  else if (direction == Direction::down) {
    new_y += 1;  // Go Down
  }
  else if (direction == Direction::right) {
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
        gui.Losing();
        return;
      }
    }
  }

  location.first = new_x;
  location.second = new_y;
  field.visual[location.second][location.first] = "P ";
}

void Player::GetCoin(Field& field, Gui& gui) {
  if (score == field.GetNumCoins()) {
    game = false;
    gui.Win();
  }

  for (auto it = field.available_coins.begin(); it != field.available_coins.end(); ++it) {
    if (location.second == it->second && location.first == it->first) {
      score += 1;
      it = field.available_coins.erase(it);
      return;
    }
  }
}
