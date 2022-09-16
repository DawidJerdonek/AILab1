#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class NPC
{

public:
	NPC();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	

private:

	sf::RectangleShape m_enemy;
	int m_randDirection = 0;
	float m_speed = 2;

};

