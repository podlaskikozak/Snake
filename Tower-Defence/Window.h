#pragma once
#include <SFML\Graphics.hpp>
#include <string>
class Window {
public:
										Window();
										Window(const std::string& l_title, const sf::Vector2u& l_size);
										~Window();
	void								BeginDraw(); 
	void								EndDraw(); 
	void								Update();
	void								SetFPS(int fpsmax);
	bool								IsDone();
	bool								IsFullscreen();
	sf::Vector2u						GetWindowSize();
	void								ToggleFullscreen();
	void								Draw(sf::Drawable& l_drawable);
	sf::RenderWindow*					GetRenderWindow();
private:
	void								Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void								Destroy();
	void								Create();

	sf::RenderWindow					m_window;
	sf::Vector2u						m_windowSize;
	std::string							m_windowTitle;
	bool								m_isDone;
	bool								m_isFullscreen;
	int									m_fpsLimit;
};