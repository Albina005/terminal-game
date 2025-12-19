#include "ghost.h"

Ghost::Ghost(Field& field) : location({ field.getHeight() - 1, field.getWidth() - 1 }) {
}

void Ghost::setRun(bool run) {
  run_ = run;
}

void Ghost::Location(Field& field, Player& player) {
  int player_x = player.location.first;
  int player_y = player.location.second;

  if (player_x > location.first) {
    location.first++;
  }
  else if (player_x < location.first) {
    location.first--;
  }
  else if (player_y > location.second) {
    location.second++;
  }
  else if (player_y < location.second) {
    location.second--;
  }
}

void Ghost::Move(Field& field, Player& player) {
  while (run_) {
    Location(field, player);
    std::this_thread::sleep_for(std::chrono::milliseconds(speed_));
  }
}
