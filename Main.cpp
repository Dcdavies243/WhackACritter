///-------------------------
/// Includes
///-------------------------
// Libraries
#include <SFML/Graphics.hpp>
#include "critter.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>


int main()
{   ///------------------------
	/// Game Setup
	///------------------------

	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter", sf::Style::Titlebar | sf::Style::Close);


	// Timer Functionality
	sf::Clock gameClock;

	//seed RNG
	srand(time(NULL));

	//Create instance of our Critter class
	critter duck;
	duck.Setup("graphics/duck.png", 10);
	critter snake;
	snake.Setup("graphics/duck.png", 20);

	const int NUM_CRITTERS = 5;
	critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/gorilla.png",30);
	critters[1].Setup("graphics/pig.png", 40);
	critters[2].Setup("graphics/goat.png", 50);
	critters[3].Setup("graphics/walrus.png", 60);
	critters[4].Setup("graphics/owl.png", 70);
	critters[4].Setup("graphics/dog.png", 80);

	//Game Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//Score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(300, 100);

	// See if there is any pending score
	score += duck.GetPendingScore();
	duck.ClearPendingScore();

	score += snake.GetPendingScore();
	snake.ClearPendingScore();

	scoreText.setString("Score: " + std::to_string(score));


	///-------------------------
	/// Game Loop
	///-------------------------


	while (gameWindow.isOpen())
	{
		///-------------------------
		/// Input
		///-------------------------

		//TODO: Check for input

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			//process input on critters

			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}

			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		///-----------------------
		/// Update
		///-----------------------
		sf::Time FrameTime = gameClock.restart();


		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}

		scoreText.setString("Score: " + std::to_string(score));

		///-----------------------
		/// End Update
		///-----------------------


		///-----------------------
		/// Draw
		///-----------------------

		//Clear the window to single colour
		gameWindow.clear();

		//Draw Everything
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			critters[i].Draw(gameWindow);
		}

		gameWindow.draw(scoreText);
		//Display the window contents to the screen
		gameWindow.display();

		///-----------------------
		/// End Draw
		///-----------------------
	}
	//////////////////////
	//End game loop
	//////////////////////

	return 0;
}