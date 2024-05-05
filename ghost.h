#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

class Field;

class Ghost {
	int speed_ = 10000;
	bool run_ = true;
public:
	std::pair<int, int> location;
	Ghost() = default;
	Ghost(Field& field);

	void setRun(bool run);
	void Move(Field& field, Player& player);
	void Location(Field& fiels, Player& player);
};