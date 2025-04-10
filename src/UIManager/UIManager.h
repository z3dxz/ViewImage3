#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include "../IncludeSFML.h"

enum UIElementEvent {
    UEE_CREATED, // These will get called by the HANDLER. Events from SFML will be passed to the handler
    UEE_DESTROY,
    UEE_MOUSE,
    UEE_RENDER
};

enum MouseBehavior {
    MB_LEFT_DOWN,
    MB_MIDDLE_DOWN,
    MB_RIGHT_DOWN,

    MB_LEFT_UP,
    MB_MIDDLE_UP,
    MB_RIGHT_UP
};

class UIElement {
    public:
    std::string name;
    sf::Vector2i position;
    sf::Vector2i size;
    std::function<void(UIElement*, UIElementEvent, int data)> PushEvent = nullptr;
};

class UIManager {
    private:
    std::vector<UIElement> uiElements;
    UIElement* GetFrontElement(sf::Vector2i mousePosition);

    public:
    void RenderElement();
    void RegisterElement(UIElement& e);
    std::vector<UIElement>& GetElements();

    // Events

    // SFML Event Mouse
    void SFML_Bind_Mouse(sf::Vector2i mousePosition, MouseBehavior mb);

    void SFML_Bind_RenderAllElements();




    UIManager();

};