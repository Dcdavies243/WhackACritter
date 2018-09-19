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
{
	//seed RNG
	srand(time(NULL));



	//Set up from sprite
	m_texture.loadFromFile("graphics/duck.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
}

void critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}