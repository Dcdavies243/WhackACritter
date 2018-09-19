#pragma once

///-------------------------
/// Includes
///-------------------------
// Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	/// Input
	///---------------------
	void Input(sf::Event _gameEvent);

	int GetPendingScore();

	//Clear the pending score
	void ClearPendingScore();

	//Set the critter type
	void Setup(std::string _texturefile, int _pointvalue);

	///---------------------
	/// End Input
	///---------------------

	///---------------------
	/// End Behaviour
	///---------------------

	///---------------------
	/// Data
	///---------------------

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue = 1;

	///---------------------
	/// End Data
	///---------------------

}; // End critter class