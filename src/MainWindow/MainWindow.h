#pragma once
#include "../IncludeSFML.h"
#include "../UIManager/UIManager.h"

class MainWindow {
	private:

	//class TestElement;

	// SFML Window
	sf::RenderWindow window;

	sf::Vector2i vSize;

	float w_scale;

	UIManager uim;


	sf::Vector2i GetPhysicalSize();

	
public:
	inline UIManager& GetUIManager() {
		return uim;
	}
	inline sf::RenderWindow& GetWindow() {
		return window;
	}

	MainWindow();
	bool testboolean1 = false;

	void setScale();
};