#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::Font font;
  if (font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
  {
    std::cout << "Font loaded successfully" << std::endl;
  }
  else
  {
    std::cout << "Failed to load font" << std::endl;
  }
  return 0;
}
