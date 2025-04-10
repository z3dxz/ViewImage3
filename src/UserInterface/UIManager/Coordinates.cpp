#include "UIManager.h"

sf::Vector2f UIManager::Adj(sf::Vector2i input)
{
    float x = std::round((float)input.x*scale);
    float y = std::round((float)input.y*scale);
    return sf::Vector2f(x, y);
}

int UIManager::Adj(int coord) {
    return (int)std::round((float)coord*scale);
}