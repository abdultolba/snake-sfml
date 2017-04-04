//
//  SnakeGame.hpp
//  Snake_SFML_v1
//
//  Created by Abdulrahman on 3/28/17.
//  Copyright © 2017 Abdulrahman Tolba. All rights reserved.
//

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"
#include "Menu.hpp"
#include "Options.hpp"
#include "Game.hpp"

class SnakeGame{
public:
	SnakeGame();
	void run();

private:
	sf::RenderWindow window;
	sf::Music music;

	Menu mainMenu;
	Game game;
	Options options;

	int level;

	bool onMenu;
	bool onGame;
	bool onOptions;
	bool lostGame;


};

#endif /* SnakeGame-hpp */
