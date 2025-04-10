#include "TestElement.h"


TestElement::TestElement(sf::RenderWindow* _window, UIManager* _uim) {
	window = _window;
	uim = _uim;

    // test element
    test.name = "Test Element";
    test.position = {50, 50};
    test.size = {200,200};

    test.PushEvent = [this](UIElement* test, UIElementEvent e, int data) {
        testThingEvent(test, e, data);
    };

    uim->RegisterElement(test);
}



void TestElement::testThingEvent(UIElement* test, UIElementEvent e, int data) {

    switch(e) {
		case UEE_MOUSE: {
			if(data == MB_LEFT_DOWN) {
				std::cout << "Wow Clicky Down" << "\n";
			}
			std::cout << "Wow Clicky" << "\n";
			break;
		}
		case UEE_RENDER: {

			rtest.setPosition({50,50});
			rtest.setSize({200,200});
			rtest.setFillColor(sf::Color(0, 128, 0));
			rtest.setOutlineThickness(2);
			rtest.setOutlineColor(sf::Color(128,128,128));
			
			window->draw(rtest);
			break;
		}
	}
}