///-------------------------
/// Includes
///-------------------------
// Libraries
#include "critter.h"
#include <string>
#include <cstdlib>
#include <ctime>

critter::critter()
//Initilisation list
	:m_sprite()
	,m_texture()
	,m_alive(true)
	,m_deathSound()
	,m_deathBuffer()
	,m_pendingScore()
{	

	//Set up from sprite
	m_texture.loadFromFile("graphics/duck.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height);

	//Set up death sound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);
}

void critter::Draw(sf::RenderTarget& _target)
{
	if (m_alive)
	{
		_target.draw(m_sprite);


	}
}

void critter::Input(sf::Event _gameEvent)
{
	if (m_alive)
	{
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//Did they click on this critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				//They clicked it!
				m_alive = false;

				//Play death sound
				m_deathSound.play();

				//Add to pending score
				m_pendingScore += m_scoreValue;
			}
		}
	}
}

int critter::GetPendingScore()
{
	return m_pendingScore;
}

void critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void critter::Setup(std::string _textureFile, int _pointValue)
{
	//setup sprite
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;
}