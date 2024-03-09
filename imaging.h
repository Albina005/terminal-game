#ifndef PACMANH
#define PACMANH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include "player.h"
#include "field.h"
#include <algorithm>
#include <utility>

#include <windows.h>
#include <conio.h>

void SetWindowSize(const int width, const int height) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  SMALL_RECT sr;
  sr.Left = 0;
  sr.Top = 0;
  sr.Right = width - 1;
  sr.Bottom = height - 1;
  SetConsoleWindowInfo(console, TRUE, &sr);

  COORD size = { width, height };
  SetConsoleScreenBufferSize(console, size);
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

void RunGame(Player& player) {
  srand(time(nullptr));


  Field field;
  Boundaries bounds(field);
  // field.SetCoins();
  bounds.SetBoundaries(field);

  SetWindowSize(3 * field.getWidth(), field.getHeight() * 3);

  while (player.game) {
    if (_kbhit()) {
      char c = _getch();
      player.Move(c, field, bounds);
      player.GetCoin(field);
    }

    Draw(field, player, bounds);
  }
}

#endif

