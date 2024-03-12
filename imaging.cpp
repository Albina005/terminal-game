#include "imaging.h"

void SetSize(const int width, const int height) {
  initscr();
  resize_term(height, width);
  refresh();
}

void Draw(const Field& field, const Player& player, const Boundaries& bounds) {
  system("cls");
  std::cout << "Name: " << player.name << " Score: " << player.score << " Lives: " << player.lives << '\n';
  for (int i = 0; i < field.getHeight() + 1; ++i) {
    for (int j = 0; j < field.getWidth() + 1; ++j) {
      std::cout << field.visual[j][i];
    }
    std::cout << std::endl;
  }
}

bool IsKeyPressed() {
  nodelay(stdscr, TRUE);
  int ch = getch();
  if (ch != ERR) {
    ungetch(ch);
    return true;
  }
  return false;
}

int GetKeyPressed() {
  return getch();
}

void RunGame(Player& player) {
  srand(time(nullptr));

  Field field;
  Boundaries bounds(field);
  bounds.SetBoundaries(field);

  SetSize(field.getWidth() * 3, field.getHeight() * 3);

  while (player.game) {
    if (IsKeyPressed()) {
      int key = GetKeyPressed();
      player.Move(key, field, bounds);
      player.GetCoin(field);
    }

    Draw(field, player, bounds);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
