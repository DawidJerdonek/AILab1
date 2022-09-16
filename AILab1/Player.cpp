#include "Player.h"

Player::Player()
{
	m_player.setRadius(50);
	m_player.setPosition(500, 500);
	m_player.setOrigin(25, 25);
	m_player.setOutlineColor(sf::Color::Green);
	m_player.setOutlineThickness(5);
	m_player.setFillColor(sf::Color::Transparent);

	srand(time(nullptr));
	int randGenNum = rand() % 4 + 1;
	m_randDirection = randGenNum;
}

void Player::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_speed >= 5.0f)
		{
			m_speed = 5.0f;
		}
		else {
			m_speed += 0.05f;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		
		if (m_speed <= 0.05f)
		{
			m_speed = 0.05f;
		}
		else {
			m_speed -= 0.05f;
		}
	}
	else {
	
		if (m_speed > 2)
		{
			m_speed -= 0.05f;
		}

		if (m_speed < 2)
		{
			m_speed += 0.05f;
		}

	}

	
	if (m_randDirection == 1)
	{
		m_player.move(m_speed, 0);
	}
	else if (m_randDirection == 2)
	{
		m_player.move(-m_speed, 0);
	}
	else if (m_randDirection == 3)
	{
		m_player.move(0, m_speed);
	}
	else if (m_randDirection == 4)
	{
		m_player.move(0, -m_speed);
	}


	if (m_player.getPosition().x <= -50)
	{
		m_player.setPosition(1945, m_player.getPosition().y);
	}
	else if (m_player.getPosition().x >= 1970)
	{
		m_player.setPosition(-50, m_player.getPosition().y);
	}
	else if (m_player.getPosition().y >= 1130)
	{
		m_player.setPosition(m_player.getPosition().x, -50);
	}
	else if (m_player.getPosition().y <= -50)
	{
		m_player.setPosition(m_player.getPosition().x, 1130);
	}
}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_player);
}
