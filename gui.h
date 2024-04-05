#pragma once

#include <SFML/Graphics.hpp>

class Gui {
	int windowWidth;
	int windowHeight;
	sf::RenderWindow window;
public:
	Gui();
	
	sf::RenderWindow& GetWindow();

	void Display(const Field& field, const Player& player);
	void Losing();
	void Win();
	std::string GetName();
};
