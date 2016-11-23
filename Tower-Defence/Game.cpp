#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600))
, m_snake(m_world.GetBlockSize())
, m_world(sf::Vector2u(800, 600))
, m_isclicked(false)
, m_hover(false)
{
	m_window.SetFPS(30);
	m_textbox.Setup(2, 14, 350, sf::Vector2f(225, 0));
	//m_textbox.Add("SCORE " + std::to_string(m_snake.GetScore()));
	m_shape.setSize(sf::Vector2f(25, 25));
	m_shape.setFillColor(sf::Color::Cyan);
}

Game::~Game()
{

}

void Game::Render()
{
	m_window.BeginDraw();
	
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());
	m_window.Draw(m_shape);
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::HandleInput()
{
	sf::Vector2f mouse = (sf::Vector2f)sf::Mouse::getPosition(*m_window.GetRenderWindow());
	if (m_isclicked == false && m_hover == false && m_shape.getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_isclicked = true;
		m_hover = true;
	}
	if (m_hover == true && m_isclicked == true && sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_hover = false;
		m_isclicked = false;
	}
	if (m_hover == true && m_isclicked == true)
	{
		if (mouse != m_shape.getPosition())
		{
			m_shape.setPosition(mouse);
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.GetPhysicalDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.GetPhysicalDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.GetPhysicalDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.GetPhysicalDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update()
{
	
	m_window.Update();
		m_snake.Tick();	
		m_world.Update(m_snake);
	//	m_textbox.Update();
		m_textbox.Add("Clicked " + std::to_string(m_isclicked));
		m_textbox.Add("Hover" + std::to_string(m_hover));
		if (m_snake.HasLost())
		{
			m_snake.Reset();
		}
		
}

sf::Time Game::GetElapsed()
{
	return m_elapsed; 
}

void Game::RestartClock()
{
	m_elapsed += m_clock.restart();
}