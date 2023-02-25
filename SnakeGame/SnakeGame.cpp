

#include "SnakeGame.h"
#include "AllClasses.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1000, 500), "My test window");


	Snake mainSnake("Snake sprite sheet.png");
	Food apple("FoodSprite.png");

	Background bg;

	Counter pointCtr("ComicMono.ttf");


	sf::Clock snakeClock;
	sf::Clock animationClock;
	//sf::Clock fps;

	std::vector<int> freeBlock((1000 / 50) * (500 / 50));
	std::fill(freeBlock.begin() + 20, freeBlock.end(), 1);

	bool ispaused = false;
	sf::Event gameEvent;

	auto i = 0;


	while (gameWindow.isOpen()) {

		float snakeTime = snakeClock.getElapsedTime().asSeconds();
		float animationTime = animationClock.getElapsedTime().asSeconds();
		//float fps2 = fps.getElapsedTime().asSeconds();


		if (gameWindow.pollEvent(gameEvent)) {
			if (gameEvent.type == sf::Event::Closed)
				gameWindow.close();

			else if (gameEvent.type == sf::Event::KeyPressed) {

				if (gameEvent.key.code == sf::Keyboard::P) {
					ispaused = !ispaused;
				}

				else if ((mainSnake.checkConflict() || ispaused) && gameEvent.key.code == sf::Keyboard::R) {
					ispaused = 0;
					pointCtr.setTextString("Point: 0");
					apple.installFood(mainSnake, freeBlock, pointCtr);
					mainSnake.setFirstPos();
				}

			}
		}

		if (!ispaused) {

			if (!mainSnake.checkConflict()) {
				mainSnake.pressKey(animationClock);
				mainSnake.move(animationClock, animationTime);


				apple.installFood(mainSnake, freeBlock, pointCtr);
			}
			else {
				mainSnake.stopMove();
				continue;
			}

			gameWindow.clear(sf::Color(0, 141, 150));
			bg.draw(gameWindow);
			mainSnake.drawSnake(gameWindow);
			apple.draw(gameWindow);
			pointCtr.draw(gameWindow);
			gameWindow.display();
			//++i;
		}

		/*if (fps2 > 1) {
			std::cout << i << '\n';
			fps.restart();
			i = 0;
		}*/
	}

	return 0;

}
