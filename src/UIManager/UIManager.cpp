#include "UIManager.h"
#include "../ops/coordinate.h"

UIManager::UIManager() {
    // todo
}

void UIManager::RegisterElement(UIElement& e) {
    std::cout << "Registered: " << e.name;
    uiElements.push_back(e);
}

std::vector<UIElement>& UIManager::GetElements() {
    
    return uiElements;
}

UIElement* UIManager::GetFrontElement(sf::Vector2i mousePosition){
    UIElement* FrontElement = nullptr;
    
    for (UIElement& ele : uiElements) { 
        // Check coordinates
        if(mousePosition.x > ele.position.x && mousePosition.y > ele.position.y && mousePosition.x <= (ele.position.x+ele.size.x) && mousePosition.y <= (ele.position.y+ele.size.y) ) {
            // In check
            FrontElement = &ele;
        }
    }

    return FrontElement;
}

void UIManager::SFML_Bind_Mouse(sf::Vector2i mousePosition, MouseBehavior mb) {
    UIElement* f = GetFrontElement(mousePosition);
    if(f != nullptr) {
        f->PushEvent(f, UEE_MOUSE2DOWN);
    } else {
        // No element found, no event pushed
        std::cout << "No element found, no element pushed" << "\n";
    }
}

void UIManager::SFML_Bind_RenderAllElements() {
    for (UIElement& ele : uiElements) {  // TODO: Handle order of elements (z-index)
        ele.PushEvent(&ele, UEE_RENDER);
    }
}
