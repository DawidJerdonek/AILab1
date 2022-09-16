#include "NPC.h"

NPC::NPC()
{
	m_enemy.setSize(sf::Vector2f(50, 50));
	m_enemy.setPosition(1250, 500);
	m_enemy.setOrigin(25, 25);
	m_enemy.setOutlineColor(sf::Color::Red);
	m_enemy.setOutlineThickness(5);
	m_enemy.setFillColor(sf::Color::Transparent);

	int randGenNum = rand() % 4 + 1;
	m_randDirection = randGenNum;
}

void NPC::update(sf::Time t_deltaTime)
{
	if (m_randDirection == 1)
	{
		m_enemy.move(m_speed, 0);
	}
	else if (m_randDirection == 2)
	{
		m_enemy.move(-m_speed, 0);
	}
	else if (m_randDirection == 3)
	{
		m_enemy.move(0, m_speed);
	}
	else if (m_randDirection == 4)
	{
		m_enemy.move(0, -m_speed);
	}

	if (m_enemy.getPosition().x <= -25)
	{
		m_enemy.setPosition(1945, m_enemy.getPosition().y);
	}
	else if (m_enemy.getPosition().x >= 1945)
	{
		m_enemy.setPosition(-25, m_enemy.getPosition().y);
	}
	else if (m_enemy.getPosition().y >= 1105)
	{
		m_enemy.setPosition(m_enemy.getPosition().x, -25);
	}
	else if (m_enemy.getPosition().y <= -25)
	{
		m_enemy.setPosition(m_enemy.getPosition().x, 1105);
	}
}

void NPC::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemy);
}
