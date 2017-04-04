#include "SnakeGame.hpp"
#include "ResourcePath.hpp"
#include <iostream>


SnakeGame::SnakeGame() :
	music(), mainMenu(), game(), options(){
	window.create(sf::VideoMode(N * size, M * size), "Snake Version 1.0");

	if(!music.openFromFile(resourcePath() + "stereo.ogg")){
		std::cout << "Error loading stereo.ogg" << std::endl;
	}
	music.setLoop(true);
	music.play();

	onMenu = true;
	onGame = false;
	onOptions = false;
	lostGame = false;
	level = 1;
}


void SnakeGame::run(){
	
    // While the window is open...
	while(window.isOpen()){
        // If the user is on the main menu, render the window and provess their input
		if(onMenu){
			mainMenu.render(window);			
			mainMenu.processEvents(window);
            
            // If the user chooses option 0, start the game
			if(mainMenu.getSelectedItem() == 0){
				onMenu = false;
				onGame = true;
				game.reset();
				mainMenu.setSelectedItem(-1);
			}
            
            // If the user chooses option 1, direct them to the options menu
			else if(mainMenu.getSelectedItem() == 1){
				// Options
				onMenu = false;
				onOptions = true;
				mainMenu.setSelectedItem(-1);
			}
            
            // If the user chooses option 2, close the window
			else if(mainMenu.getSelectedItem() == 2){
				mainMenu.setSelectedItem(-1);
				window.close();
			}
		}
        
        // If the user is on the options menu, render the window and process their input
		else if(onOptions){
			options.render(window);
			options.processEvents(window);
            
            // Get the option they selected to set the game difficulty
			if(options.getSelectedItem() != -1){
				level = options.getSelectedItem();
				options.setSelectedItem(-1);
				onMenu = true;
				onOptions = false;
			}

		}
        
        // If the user is currently playing the game, process the game and determine when they have lost.
		else if(onGame){
			game.setPlaying(true);
			game.setLevel(level);
			game.play(window);
			onGame = game.getPlaying();
			if(!onGame){
				lostGame = true;
			}
		}
        
        // If the user loses the game, return to the main menu
		else if(lostGame){
			onMenu = true;	
			lostGame = false;
		}
	}
}
