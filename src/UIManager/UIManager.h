#pragma once

#include <vector>
#include <iostream>
#include <string>
#include "../IncludeSFML.h"

class UIElement {
    public:
    std::string name;
    sf::Vector2i position;
    sf::Vector2i size;
    sf::RectangleShape _r;
};

class UIManager {
    private:
    std::vector<UIElement> uiElements;

    public:
    void RenderElement();
    std::vector<UIElement>& GetElements();

    UIManager();

};