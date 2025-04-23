#include "MainWindow.h"
#include <iostream>
#include "../dialog/sfdialog.h"
#include "../UserInterface/uilist.h"
// Only windows

sf::Vector2i MainWindow::GetPhysicalSize() {
	sf::Vector2i s;
	s.x = (int)((float)vSize.x*w_scale);
	s.y = (int)((float)vSize.y*w_scale);
	return s;
}

MainWindow::MainWindow() {
	// Define default parameters

	vSize = { 1024, 576 }; // From old edition

	// Create window
	sf::Vector2i physicalSize = GetPhysicalSize();
	sf::RenderWindow window(sf::VideoMode(physicalSize.x, physicalSize.y), "View Image", sf::Style::Default);
	window.setFramerateLimit(60);

	// make test

	TestElement k = TestElement(&window, &uim, 40, 40, "Oh my first");

	TestElement ko = TestElement(&window, &uim, 100, 100, "Oh my second");

	//for(int i=0; i<500; i++){
	//	TestElement* ko0 = new TestElement(&window, &uim, rand()%1000, rand()%700, "Oh my second");
	//}

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
		

		window.clear(sf::Color(128, 128, 128));

		testboolean1 = true;

		uim.SFML_Bind_RenderAllElements();

		testboolean1 = false;



		window.display();
	}
}