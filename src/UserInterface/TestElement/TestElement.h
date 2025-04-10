#pragma once
#include "../UIManager/UIManager.h"

class TestElement {
    public:

    TestElement(sf::RenderWindow* _window, UIManager* _uim, int posx, int posy, std::string custom_text);

    private:

    sf::RenderWindow* window;
    UIManager* uim;

    UIElement test;
	sf::RectangleShape rtest;
	void testThingEvent(UIElement* test, UIElementEvent e, int data, std::string custom_text);

};