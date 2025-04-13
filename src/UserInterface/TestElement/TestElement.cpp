#include "TestElement.h"


TestElement::TestElement(sf::RenderWindow* _window, UIManager* _uim, int posx, int posy, std::string custom_text) {
	window = _window;
	uim = _uim;

    // test element
    test.name = "Test Element";
    test.position = {50+posx, 50+posy};
    test.size = {20,20};

    test.PushEvent = [this, custom_text](UIElement* test, UIElementEvent e, int data) {
        testThingEvent(test, e, data, custom_text);
    };

    uim->RegisterElement(&test);
}

TestElement::~TestElement() {
	uim->UnRegisterElement(&test);
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
			rtest.setPosition(uim->Adjf(test->position));
			rtest.setSize(uim->Adjf(test->size));
			sf::Vector2 mp = sf::Mouse::getPosition(*window);
			if(uim->GetFrontElement(mp) == test){
				rtest.setFillColor(sf::Color(0, 128, 0));
			} else {
				rtest.setFillColor(sf::Color(0, 0, 128));
			}
			rtest.setOutlineThickness(std::floor(uim->Adjf(1)));
			rtest.setOutlineColor(sf::Color(255,255,255));
			
			window->draw(rtest);
			break;
		}
	}
}