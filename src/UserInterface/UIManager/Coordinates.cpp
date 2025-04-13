#include "UIManager.h"

sf::Vector2i UIManager::Adji(sf::Vector2i input)
{
    float x = std::round((float)input.x*scale);
    float y = std::round((float)input.y*scale);
    return sf::Vector2i((int)x, (int)y);
}

int UIManager::Adji(int coord) {
    return (int)std::round((float)coord*scale);
}

sf::Vector2f UIManager::Adjf(sf::Vector2i input)
{
    float x = (float)input.x*scale;
    float y = (float)input.y*scale;
    return sf::Vector2f(x, y);
}

float UIManager::Adjf(float coord) {
    return (float)coord*scale;
}