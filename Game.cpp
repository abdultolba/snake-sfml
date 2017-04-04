#include "Game.hpp"
#include "config.hpp"
#include "ResourcePath.hpp"
#include <iostream>

Game::Game(){

    // Load the snake body (red square)
	if(!texture2.loadFromFile(resourcePath() + "red.png")){
		std::cout << "Error loading red.png" << std::endl;
	}
    
    // Load the snake food (green square)
	if(!texture3.loadFromFile(resourcePath() + "green.png")){
		std::cout << "Error loading green.png" << std::endl;
	}
	
	sprite1.setTexture(texture1);
	sprite2.setTexture(texture2);
	sprite3.setTexture(texture3);
	
	reset();

	timer = 0, delay = 0.1;
	playing = true;

}

void Game::reset(){
	direction = 1;

	for(int i = 0; i < 100; i++)
		snake[i].x = 0, snake[i].y = 0;

	snakeLength = 2;
	
	srand(time(0));
	
	fruit.x = rand() % N;
	fruit.y = rand() % M;

}

void Game::play(sf::RenderWindow &window){
	float time = timeClock.getElapsedTime().asSeconds();
	timeClock.restart();
	timer += time;
	processEvents(window);

	if(timer > delay){
		timer = 0;
		update();
		render(window);
	}

}

bool Game::getPlaying(){
	return playing;
}

void Game::setPlaying(bool b){
	playing = b;
}

void Game::setLevel(int level){
	if(level == 0)
		delay = 0.15;
	else if(level == 1)
		delay = 0.10;
	else if(level == 2)
		delay = 0.05;
	else
		delay = 0.1;
}

void Game::processEvents(sf::RenderWindow &window){
	sf::Event event;

	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
		else if(event.type == sf::Event::KeyPressed)
			handlePlayerInput(event.key.code);
		
	}
}

void Game::update(){
    // If the snake reaches the fruit, generate a new fruit and increment the snake length
	if(snake[0].x == fruit.x && snake[0].y == fruit.y){
		fruit.x = rand() % N;
		fruit.y = rand() % M;
		snakeLength++;
	}
	
    // Adding a new square to the snakes body
	for(int i = snakeLength - 1; i > 0; i--){
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}

	if(direction == 0 && snake[0].y - 1 != snake[1].y)
		snake[0].y -= 1;
	else if(direction == 1 && snake[0].y + 1 != snake[1].y)
		snake[0].y += 1;
	else if(direction == 2 && snake[0].x - 1 != snake[1].x)
		snake[0].x -= 1;
	else if(direction == 3 && snake[0].x + 1 != snake[1].x)
		snake[0].x += 1;


    if(snake[0].x >= N)
        playing = false;
    if(snake[0].x < 0)
        playing = false;
	if(snake[0].y >= M)
        playing = false;
	if(snake[0].y < 0)
		playing = false;


	for(int i = 1; i < snakeLength; i++){
		if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
			snakeLength = 2;
			playing = false;
			break;
		}
	}
}

void Game::render(sf::RenderWindow &window){
	window.clear();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			sprite1.setPosition(i * size, j * size);
			window.draw(sprite1);
		}
	}

	for(int i = 0; i < snakeLength; i++){
		sprite2.setPosition(snake[i].x * size, snake[i].y * size);
		window.draw(sprite2);
	}
	
	sprite3.setPosition(fruit.x * size, fruit.y * size);
	window.draw(sprite3);
	window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key){
    if((key == sf::Keyboard::Up || key == sf::Keyboard::W) && direction != 1)
		direction = 0;
	else if((key == sf::Keyboard::Down || key == sf::Keyboard::S) && direction != 0)
		direction = 1;
	else if((key == sf::Keyboard::Left || key == sf::Keyboard::A) && direction != 3)
		direction = 2;
	else if((key == sf::Keyboard::Right || key == sf::Keyboard::D) && direction != 2)
		direction = 3;
}


