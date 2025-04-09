#include "TestElement.h"


TestElement::TestElement() {

    // test element
    test.name = "Test Element";
    test.position = {50, 50};
    test.size = {200,200};

    test.PushEvent = [this](UIElement* test, UIElementEvent e) {
        testThingEvent(test, e);
    };

    GetUIManager().RegisterElement(test);
}



void TestElement::testThingEvent(UIElement* test, UIElementEvent e) {

    switch(e) {
		case UEE_MOUSE1DOWN: {
			generateBeep(500, 506);
			break;
		}
		case UEE_RENDER: {

			rtest.setPosition({50,50});
			rtest.setSize({200,200});
			rtest.setFillColor(sf::Color(0, 128, 0));
			rtest.setOutlineThickness(2);
			rtest.setOutlineColor(sf::Color(128,128,128));

			GetWindow().draw(rtest);
			break;
		}
	}
}