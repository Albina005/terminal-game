#include "imaging.h"
#include "player.h"
#include "field.h"
#include "gui.h"
#include "ghost.h"

void RunGame(Player& player, Gui& gui) {
  srand(time(nullptr));
  Field field;
  Ghost ghost(field);
  Boundaries bounds(field);
  field.SetField(player, ghost, bounds);
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
        ghost.Location(field, player);
        player.Move(gui, direction, field, bounds, ghost);
        player.GetCoin(field, gui);
        field.SetField(player, ghost, bounds);
        gui.Display(field, player);
      }


    }

  }

}

