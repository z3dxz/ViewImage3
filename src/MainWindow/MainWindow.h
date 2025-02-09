#pragma once
#include "../IncludeSFML.h"
#include "../UIManager/UIManager.h"

class MainWindow {
	// SFML Window
	sf::RenderWindow window;

	sf::Vector2i virtualSize;
	sf::Vector2i physicalSize;

	float w_scale;

	UIManager uim;

	void UpdatePhysicalSize();
public:
	MainWindow();
};