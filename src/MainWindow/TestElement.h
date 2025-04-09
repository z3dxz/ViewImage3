#pragma once
#include "MainWindow.h"

class TestElement {
    public:

    TestElement();

    private:

    UIElement test;
	sf::RectangleShape rtest;
	void testThingEvent(UIElement* test, UIElementEvent e);


};
