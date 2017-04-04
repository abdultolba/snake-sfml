//
//  Menu_hpp
//  Snake_SFML_v1
//
//  Created by Abdulrahman on 3/28/17.
//  Copyright © 2017 Abdulrahman Tolba. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu{
public:
    // Default constructor to display the main menu options
	Menu();
    // Handle a users given event
	void processEvents(sf::RenderWindow &window);
    // Render the application window
	void render(sf::RenderWindow &window);
    // Move an option up
	void moveUp();
    // Move an option down
	void moveDown();
    // Return the selected item
	int getSelectedItem() const;
    // Set the selected item
	void setSelectedItem(int item);
protected:
    // Handle users keyboard input
	void handlePlayerInput(sf::Keyboard::Key key);	
	int selectedItem;
	int currentItem;
	
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif /* Menu_hpp */
