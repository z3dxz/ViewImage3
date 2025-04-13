#include "UIManager.h"
#include <algorithm>

UIManager::UIManager(float _scale) {
    scale = _scale;
}


void UIManager::RegisterElement(UIElement* e) {
    //std::cout << "Registered: " << e->name << "\n";
    // Adds element to vector
    uiElements.push_back(e);
}

void UIManager::UnRegisterElement(UIElement *e){
    // Find and remove the missing element

    auto it = std::find(uiElements.begin(), uiElements.end(), e);
    if (it != uiElements.end()) {
        uiElements.erase(it);
    } else {
        std::cout << "Can not unregister element";
    }
}

std::vector<UIElement*>& UIManager::GetElements() {
    // Returns the UI element vector
    return uiElements;
}

UIElement* UIManager::GetFrontElement(sf::Vector2i mousePosition){
    UIElement* FrontElement = nullptr;
    
    for (UIElement* ele : uiElements) { 
        // Check coordinates
        if(mousePosition.x > Adji(ele->position.x) && mousePosition.y > Adji(ele->position.y) && mousePosition.x <= (Adji(ele->position.x)+Adji(ele->size.x)) && mousePosition.y <= (Adji(ele->position.y)+Adji(ele->size.y)) ) {
            // In check
            FrontElement = ele;
        }
    }

    return FrontElement;
}

// SFML Bind Events

void UIManager::SFML_Bind_Mouse(sf::Vector2i mousePosition, MouseBehavior mb) {
    UIElement* f = GetFrontElement(mousePosition);
    if(f != nullptr) {
        f->PushEvent(f, UEE_MOUSE, mb);
    } else {
        // No element found, no event pushed
        std::cout << "No element found, no element pushed" << "\n";
    }
}

void UIManager::SFML_Bind_RenderAllElements() {
    for (UIElement* ele : uiElements) {  // TODO: Handle order of elements (z-index)
        (*ele).PushEvent(ele, UEE_RENDER, 0);
    }
}
