#include "MainWindow.h"
#include <iostream>

void MainWindow::UpdatePhysicalSize() {
	physicalSize.x = (int)((float)virtualSize.x*w_scale);
	physicalSize.y = (int)((float)virtualSize.y*w_scale);
}

MainWindow::MainWindow() {
	// Define default parameters
	w_scale = 1.0f; // temporarially

	virtualSize = { 1024, 576 }; // From old edition
	UpdatePhysicalSize();
	
	// Create window
	sf::RenderWindow window(sf::VideoMode(physicalSize.x, physicalSize.y), "View Image", sf::Style::Default);


	// Poll Events
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
	
			if (event.type == sf::Event::Closed) {
				window.close();
			} 
			
			if (event.type == sf::Event::Resized) {
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
	
				virtualSize.x = event.size.width;
				virtualSize.y = event.size.height;
				UpdatePhysicalSize();
			}
		}
		
		window.clear({128, 128, 0});
		window.display();
	}
}