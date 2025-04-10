#include "TestElement.h"


TestElement::TestElement(sf::RenderWindow* _window, UIManager* _uim, int posx, int posy, std::string custom_text) {
	window = _window;
	uim = _uim;

    // test element
    test.name = "Test Element";
    test.position = {50+posx, 50+posy};
    test.size = {200,200};

    test.PushEvent = [this, custom_text](UIElement* test, UIElementEvent e, int data) {
        testThingEvent(test, e, data, custom_text);
    };

    uim->RegisterElement(test);
}



void TestElement::testThingEvent(UIElement* test, UIElementEvent e, int data, std::string custom_text) {

    switch(e) {
		case UEE_MOUSE: {
			if(data == MB_LEFT_DOWN) {
				std::cout << custom_text << "\n";
			}
			break;
		}
		case UEE_RENDER: {

			rtest.setPosition(uim->Adj(test->position));
			rtest.setSize(uim->Adj(test->size));
			sf::Vector2 mp = sf::Mouse::getPosition(*window);
			if(uim->GetFrontElement(mp) == test){
				rtest.setFillColor(sf::Color(0, 128, 0));
			} else {
				rtest.setFillColor(sf::Color(0, 0, 128));
			}
			rtest.setOutlineThickness(2);
			rtest.setOutlineColor(sf::Color(128,128,128));
			
			window->draw(rtest);
			break;
		}
	}
}