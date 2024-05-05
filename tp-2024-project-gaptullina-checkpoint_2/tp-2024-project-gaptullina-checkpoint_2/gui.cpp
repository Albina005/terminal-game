#include "imaging.h"
#include "player.h"
#include "field.h"
#include "gui.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

Gui::Gui() {

  windowWidth = 800;
  windowHeight = 600;

  window.create(sf::VideoMode(windowWidth, windowHeight), "Display");
}

sf::RenderWindow& Gui::GetWindow() {
  return window;
}

std::string Gui::GetName() {
  std::string name;

  sf::Font font;
  sf::Text inputText("", font, 24);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      else if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !name.empty()) { // "Backspace"
          name.pop_back();
        }
        else if (event.text.unicode == '\n') { // "Enter"
          return name;
        }
        else if (event.text.unicode > 30 && event.text.unicode < 127) { // добавляем символ
          name += static_cast<char>(event.text.unicode);
        }
        inputText.setString(name);
      }
    }

  }
  return "";
}

void Gui::Display(const Field& field, const Player& player) {
  const std::vector<std::vector<std::string>>& visual = field.visual;
  int arrayWidth = field.getWidth();
  int arrayHeight = field.getHeight() + 1;

  const int itemWidth = windowWidth / (arrayWidth);
  const int itemHeight = windowHeight / arrayHeight;

  std::vector<std::vector<sf::RectangleShape>> rectangles(arrayHeight, std::vector<sf::RectangleShape>(arrayWidth));

  const int itemWidthForScore = windowWidth / (arrayWidth + player.getLives() + player.score);

  for (int i = 0; i < player.getLives(); ++i) {

    rectangles[arrayWidth][i].setFillColor(sf::Color::Green);
    rectangles[arrayWidth][i].setSize(sf::Vector2f(itemWidthForScore, itemHeight));
    rectangles[arrayWidth][i].setPosition(i * itemWidthForScore, (arrayHeight - 1) * itemHeight);
    window.draw(rectangles[arrayWidth][i]);
  }

  for (int i = player.getLives(); i < player.getLives() + player.score; ++i) {
    rectangles[arrayWidth][i].setFillColor(sf::Color::Yellow);
    rectangles[arrayWidth][i].setSize(sf::Vector2f(itemWidth, itemHeight));
    rectangles[arrayWidth][i].setPosition(i * itemWidth, (arrayHeight - 1) * itemHeight);
    window.draw(rectangles[arrayWidth][i]);
  }

  for (int i = 0; i < arrayHeight - 1; ++i) {
    for (int j = 0; j < arrayWidth; ++j) {
      if (visual[i][j] == "P ") {
        rectangles[i][j].setFillColor(sf::Color::Red);
      }
      else if (visual[i][j] == "# ") {
        rectangles[i][j].setFillColor(sf::Color::Blue);
      }
      else if (visual[i][j] == "0 ") {
        rectangles[i][j].setFillColor(sf::Color::Yellow);
      }

      rectangles[i][j].setSize(sf::Vector2f(itemWidth, itemHeight));
      rectangles[i][j].setPosition(j * itemWidth, i * itemHeight);

      window.draw(rectangles[i][j]);
    }
  }

  window.display();
}



void Gui::Losing() {
  window.clear(sf::Color::Red);

  //sf::Font font;
  //sf::Text messageText("You lost", font, 24);

  //messageText.setFillColor(sf::Color::Black);
  //messageText.setPosition(10, 10);

  //window.draw(messageText);
  window.display();
  sf::sleep(sf::seconds(2));
  window.close();
}

void Gui::Win() {
  window.clear(sf::Color::Green);

  //sf::Font font;
  //sf::Text messageText("You win", font, 24);

  //messageText.setFillColor(sf::Color::Black);
  //messageText.setPosition(10, 10);

  //window.draw(messageText);
  window.display();
  sf::sleep(sf::seconds(2));
  window.close();
}

