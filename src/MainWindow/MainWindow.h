#pragma once
#include "../IncludeSFML.h"
#include "../UserInterface/UIManager/UIManager.h"

class MainWindow {
	private:

	//class TestElement;

	// SFML Window
	sf::RenderWindow window; 

	VCoord size;

	float w_scale = 1.25f;

	UIManager uim = UIManager(&w_scale);

public:
	inline UIManager& GetUIManager() {
		return uim;
	}
	inline sf::RenderWindow& GetWindow() {
		return window;
	}

	MainWindow();

	void setScale();
};