//
//  Game.hpp
//  Snake_SFML_v1
//
//  Created by Abdulrahman on 3/28/17.
//  Copyright © 2017 Abdulrahman Tolba. All rights reserved.
//
#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>

struct Snake{
	int x, y;
};

struct Fruit{
	int x, y;
};

class Game{
public:
	Game();
	void reset();
	void play(sf::RenderWindow &window);
	bool getPlaying();
	void setPlaying(bool b);
	void setLevel(int level);
private:
	void processEvents(sf::RenderWindow &window);
	void update();
	void render(sf::RenderWindow &window);
	void handlePlayerInput(sf::Keyboard::Key key);
	
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;

	sf::Clock timeClock;

	Snake snake[100];
	Fruit fruit;
	int direction;
	int snakeLength;
		
	float timer, delay;

	bool playing;
};

#endif /* Game_hpp */
