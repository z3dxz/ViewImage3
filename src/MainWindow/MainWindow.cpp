#include "MainWindow.h"
#include <iostream>
#include "../dialog/sfdialog.h"
#include "TestElement.h"

sf::Vector2i MainWindow::GetPhysicalSize() {
	sf::Vector2i s;
	s.x = (int)((float)vSize.x*w_scale);
	s.y = (int)((float)vSize.y*w_scale);
	return s;
}




MainWindow::MainWindow() {
	// Define default parameters
	w_scale = 1.0f; // temporarially

	vSize = { 1024, 576 }; // From old edition

	// Create window
	sf::Vector2i physicalSize = GetPhysicalSize();
	sf::RenderWindow window(sf::VideoMode(physicalSize.x, physicalSize.y), "View Image", sf::Style::Default);

	// make test

	TestElement k = TestElement(&window, &uim);
	
	// Poll Events
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
	
				vSize.x = event.size.width;
				vSize.y = event.size.height;
			}
		}
		

		window.clear(sf::Color(0, 128, 128));

		testboolean1 = true;

		uim.SFML_Bind_RenderAllElements();

		testboolean1 = false;

		window.display();
	}
}