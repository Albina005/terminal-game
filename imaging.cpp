#include "imaging.h"
#include "player.h"
#include "field.h"

#include <iostream>

class IOManager {
public:
  virtual std::istream& Input() = 0;
  virtual std::ostream& Output() = 0;
  virtual ~IOManager() {}
};

class ConsoleManager {
public:
  std::ostream& Output(std::ostream& out, const Field& field, const Player& player) const {
    system("gnome-terminal");
    out << "Name: " << player.getName() << " Score: " << player.score << " Lives: " << player.getLives() << '\n';
    for (int i = 0; i < field.getHeight(); ++i) {
      for (int j = 0; j < field.getWidth(); ++j) {
        out << field.visual[i][j];
      }
      out << '\n';
    }
    return out;
  }
};

void SetSize(const int width, const int height) {
  initscr();
  resize_term(height, width);
  refresh();
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
  ConsoleManager console;
  Field field;
  Boundaries bounds(field);
  bounds.SetBoundaries(field);

  SetSize(field.getWidth() * 3, field.getHeight() * 3);

  while (player.getGame()) {
    if (IsKeyPressed()) {
      Direction direction;
      int key = GetKeyPressed();
      if (key == 'w' || key == 72) {
        direction = up;
      }
      else if (key == 'a' || key == 75) {
        direction = left;
      }
      else if (key == 's' || key == 80) {
        direction = down;
      }
      else if (key == 'd' || key == 77) {
        direction = right;
      }
      else {
        direction = undefined;
      }


      player.Move(direction, field, bounds);
      player.GetCoin(field);
    }

    console.Output(std::cout, field, player);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
