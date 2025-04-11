#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include "../../IncludeSFML.h"

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
    // Vector to store all the UI elements
    std::vector<UIElement*> uiElements;

    

    public:

    // DPI Scaling value
    float scale;

    // Gets the front-most element the mouse is touching
    UIElement* GetFrontElement(sf::Vector2i mousePosition);

    // Appends element to uiElements, registers it with UIManager
    void RegisterElement(UIElement* e);
    void UnRegisterElement(UIElement* e);

    // Returns the uiElements vector
    std::vector<UIElement*>& GetElements();

    // Events that SFML call/bind to UIManager
    void SFML_Bind_Mouse(sf::Vector2i mousePosition, MouseBehavior mb);
    void SFML_Bind_RenderAllElements();

    UIManager(float _scale);

    // coordinates

    sf::Vector2f Adj(sf::Vector2i input);
    int Adj(int coord);

};