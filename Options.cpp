#include "Options.hpp"
#include "ResourcePath.hpp"
#include <iostream>

Options::Options(){
	if(!font.loadFromFile(resourcePath() + "arial.ttf")){
		std::cout << "Error loading arial.ttf" << std::endl;
	}
	
    // Option to set the difficulty to 'Novice' (Easy)
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setPosition((N * size) / 2 - 35, (M * size) / 4 * 1);
	menu[0].setString("Novice");
	
    // Option to set the difficulty to 'Intermediate' (Medium)
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition((N * size) / 2 - 75, (M * size) / 4 * 2);
	menu[1].setString("Intermediate");

    // Option to set the difficulty to 'Expert' (Hard)
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition((N * size) / 2 - 35, (M * size) / 4 * 3);
	menu[2].setString("Expert");
	
	currentItem = 0;
	selectedItem = -1;
}


