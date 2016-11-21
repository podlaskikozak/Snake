#pragma once
#include <SFML\Graphics.hpp>
#include <vector>


enum class Direction { None, Up, Down, Left, Right };

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;
