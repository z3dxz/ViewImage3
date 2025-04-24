#include "MainWindow.h"
#include <iostream>
#include "../dialog/sfdialog.h"
#include "../UserInterface/uilist.h"

// Only windows
#ifdef _WIN32
#include "windows_exclusive/titlebar.h"
#endif


MainWindow::MainWindow() {
	// Define default parameters

	size = { 1024, 576 }; // From old edition

	// Create window
	sf::Vector2i physicalSize = uim.ProjectI(size);
	sf::RenderWindow window(sf::VideoMode(physicalSize.x, physicalSize.y), "View Image", sf::Style::Default);
	
	// Poll Events
	#ifdef _WIN32
	SetTitlebarDark(window);
	#endif


	window.setFramerateLimit(60);

	// make test

	TestElement k = TestElement(&window, &uim, 40, 40, "Oh my first");

	TestElement ko = TestElement(&window, &uim, 100, 100, "Oh my second");

	

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if((event.type == sf::Event::MouseButtonPressed) || (event.type == sf::Event::MouseButtonReleased)) {
				bool released = event.type == sf::Event::MouseButtonReleased;
				sf::Vector2i pos = sf::Mouse::getPosition(window);

				if (event.mouseButton.button == sf::Mouse::Left) {
					uim.SFML_Bind_Mouse(pos, released ? MB_LEFT_UP : MB_LEFT_DOWN);
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					uim.SFML_Bind_Mouse(pos, released ? MB_RIGHT_UP : MB_RIGHT_DOWN);
				}
				if (event.mouseButton.button == sf::Mouse::Middle) {
					uim.SFML_Bind_Mouse(pos, released ? MB_RIGHT_UP : MB_RIGHT_DOWN);
				}
			}
			
			if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				sf::Vector2i coord = sf::Vector2i({(int)event.size.width, (int)event.size.height});
				VCoord newcoord = uim.Virtualize(coord);
				size.x = newcoord.x;
				size.y = newcoord.y;
			}
		}
		

		window.clear(sf::Color(8,8,8));

		uim.SFML_Bind_RenderAllElements();
		
		window.display();
	}
}