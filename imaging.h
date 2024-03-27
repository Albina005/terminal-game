#ifndef IMAGING_H
#define IMAGING_H

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

#include <ncurses.h>
class IOManager;
class ConsoleManager;

void SetSize(const int width, const int height);
// void Draw(const Field& field, const Player& player, const Boundaries& bounds);
bool IsKeyPressed();
int GetKeyPressed();
void RunGame(Player& player);

#endif
