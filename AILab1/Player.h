#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{

public:
	Player();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);


private:

	sf::CircleShape m_player;
	int m_randDirection = 0;
	float m_speed = 2;
};

