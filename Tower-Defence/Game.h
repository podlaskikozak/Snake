#pragma once
#include <SFML\Graphics.hpp>
#include "Locals.h"
#include "Window.h"
#include "World.h"
#include "TextBox.h"
#include <iostream>

class Game {
public:
											Game();
											~Game();
	void									HandleInput();
	void									Update();
	void									Render();
	Window*									GetWindow();
	sf::Time								GetElapsed();
private:
	void									RestartClock();
	Window									m_window;
	sf::Texture								m_mushroomTexture;
	sf::Sprite								m_mushroom;
	sf::Vector2f							m_increment;
	World									m_world;
	Snake									m_snake;
	Textbox									m_textbox;
	sf::Time								m_elapsed;
	sf::Clock								m_clock;
	sf::RectangleShape						m_shape;
	bool									m_isclicked;
	bool									m_hover;
};
