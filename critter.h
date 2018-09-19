#pragma once

///-------------------------
/// Includes
///-------------------------
// Libraries
#include <SFML/Graphics.hpp>

class critter
{
	///---------------------
    /// Behaviour
    ///---------------------
public:

	//Contructor
	critter();

	void Draw(sf::RenderTarget& _target);
	///---------------------
	/// End Behaviour
	///---------------------

	///---------------------
	/// Data
	///---------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	///---------------------
	/// End Data
	///---------------------

}; // End critter class