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
		case UEE_CREATED: {
			// Nothing
			break;
		}
		case UEE_DESTROY: {
			// Nothing
			break;
		}
		case UEE_MOUSE: {
			if(data == MB_LEFT_DOWN) {
				std::cout << custom_text << "\n";
			}
			break;
		}
		case UEE_RENDER: {
			rtest.setPosition(uim->ProjectF(test->position));
			rtest.setSize(uim->ProjectF(test->size));
			sf::Vector2 mp = sf::Mouse::getPosition(*window);
			if(uim->GetFrontElement(uim->Virtualize(mp)) == test){
				rtest.setFillColor(sf::Color(0, 60, 255));
			} else {
				rtest.setFillColor(sf::Color(60, 128, 128));
			}
			rtest.setOutlineThickness(1);
			rtest.setOutlineColor(sf::Color(255,255,255));
			
			window->draw(rtest);
			break;
		}
	}
}