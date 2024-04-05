#include "imaging.h"
#include "player.h"
#include "field.h"
#include "gui.h"


void RunGame(Player& player, Gui& gui) {
  srand(time(nullptr));
  Field field;
  Boundaries bounds(field);
  bounds.SetBoundaries(field);

  sf::RenderWindow& window = gui.GetWindow();

  while (player.getGame() && window.isOpen()) {
    sf::Event event;
    gui.Display(field, player);
    Direction direction;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      else if (event.type == sf::Event::KeyPressed) {
      
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
          direction = Direction::up;
        }
        else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
          direction = Direction::left;
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
          direction = Direction::down;
        }
        else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
          direction = Direction::right;
        }
        else {
          direction = Direction::undefined;
        }
        player.Move(gui, direction, field, bounds);
        player.GetCoin(field, gui);
        gui.Display(field, player);
      }


    }

  }

}

