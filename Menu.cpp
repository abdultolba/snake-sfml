#include "Menu.hpp"
#include "ResourcePath.hpp"
#include <iostream>

Menu::Menu(){
	if(!font.loadFromFile(resourcePath() + "arial.ttf")){
		std::cout << "Error loading arial.ttf" << std::endl;
	}
	
    // 'Play' Option
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setPosition((N * size) / 2 - 35, (M * size) / 4 * 1);
	menu[0].setString("Play");
	
    // Go to the 'Options' Menu
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition((N * size) / 2 - 50, (M * size) / 4 * 2);
	menu[1].setString("Options");
    
    // Terminate the program
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition((N * size) / 2 - 35, (M * size) / 4 * 3);
	menu[2].setString("Quit");
	
	currentItem = 0;
	selectedItem = -1;
}

void Menu::processEvents(sf::RenderWindow &window){
	sf::Event event;
    
    // While there are pending events...
	while(window.pollEvent(event)){
        // Check the type of event
		if(event.type == sf::Event::Closed)
			window.close();
        // If a key is pressed, the handlePlayerInput function will
        // determine what action to take
		else if(event.type == sf::Event::KeyPressed)
			handlePlayerInput(event.key.code);
	}
}

void Menu::render(sf::RenderWindow &window){
	window.clear();
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window.draw(menu[i]);
	}
	window.display();
}


void Menu::moveUp(){
    // If the user is not at the first option,
    // go to the previous option
	if(currentItem != 0){
		menu[currentItem].setFillColor(sf::Color::White);
		currentItem--;
		menu[currentItem].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown(){
    // If the user is not at the last option,
    // go to the next available option
	if(currentItem != 2){
		menu[currentItem].setFillColor(sf::Color::White);
		currentItem++;
		menu[currentItem].setFillColor(sf::Color::Red);
	}
}

int Menu::getSelectedItem() const{
    // Return the selected item
	return selectedItem;
}

void Menu::setSelectedItem(int item){
    // Set the selected item
	selectedItem = -1;
}


void Menu::handlePlayerInput(sf::Keyboard::Key key){
    // If the user clicks the up button or 'W' (WASD) on the keyboard
    if(key == sf::Keyboard::Up || key == sf::Keyboard::W){
		moveUp();
	}
    // If the user clicks the down button or 'S' (WASD) on the keyboard
    else if(key == sf::Keyboard::Down || key == sf::Keyboard::S){
		moveDown();
	}
    // If the user clicks enter / return
	else if(key == sf::Keyboard::Return){
		selectedItem = currentItem;
	}
}
