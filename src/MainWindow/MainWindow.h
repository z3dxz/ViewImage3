#pragma once
#include "../IncludeSFML.h"
#include "../UserInterface/UIManager/UIManager.h"

class MainWindow {
	private:

	//class TestElement;

	// SFML Window
	sf::RenderWindow window; 

	sf::Vector2i vSize;


	float w_scale = 1.0f;

	UIManager uim = UIManager(w_scale);


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