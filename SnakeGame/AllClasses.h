#pragma once

#include "SnakeGame.h"

class Snake {
public:
	explicit Snake(std::string name);


	sf::Sprite& operator [](const int i);


	void pressKey(sf::Clock& animationClock);

	void move(sf::Clock& animationClock, float& animationTime);

	sf::Vector2f getPosition(const int8_t spNum);

	void setPosition(int8_t spNum, const float& x, const float& y);

	std::vector <sf::Sprite>& getSnake();

	size_t getSnakeSize();

	void pushBack(sf::Sprite last);

	sf::Sprite& lastBlock();

	void drawSnake(sf::RenderWindow& window);

	sf::Vector2f& getPlaceForNext();

	bool checkConflict();

	void stopMove();

	void setFirstPos();

	sf::Sprite& getPenaltimateSp();

	float getTailRotate();

private:

	int dx, dy;
	sf::Vector2f placeForNext;
	sf::Texture snakeTexture;
	std::vector <sf::Sprite> snakeSp;
	sf::Sprite penaltimate;
	float tailRotate;
};


class Counter {
public:
	Counter(std::string fontName);


	const std::string& getTextString() const;

	void setTextString(const std::string& tmp);

	void setTextPosition(int x, int y);

	void draw(sf::RenderWindow& window);

private:
	const sf::FloatRect& getTextLocalBound() const;
	sf::Font ctrFont;
	sf::Text ctrText;


};



//Class Food
class Food {
public:
	Food(std::string filename);


	void installFood(Snake& snake, std::vector<int>& freeBlock, Counter& ctr);
	void draw(sf::RenderWindow& window);

private:

	sf::Texture foodTexture;
	sf::Sprite foodSp;
};




//Background class
class Background {
public:
	Background();
	void  draw(sf::RenderWindow& window);

private:

	sf::RenderTexture bgRendTex;
	sf::Sprite bgSp;
};