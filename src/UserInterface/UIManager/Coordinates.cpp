#include "UIManager.h"
/*
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
*/

sf::Vector2f UIManager::ProjectF(VCoord coordinate) {

    float x = (float)coordinate.x*(*scaleValue);
    float y = (float)coordinate.y*(*scaleValue);

    return sf::Vector2f({x,y});
}

sf::Vector2i UIManager::ProjectI(VCoord coordinate) {

    int x = (int)((float)coordinate.x*(*scaleValue));
    int y = (int)((float)coordinate.y*(*scaleValue));

    return sf::Vector2i({x,y});
}

VCoord UIManager::Virtualize(sf::Vector2f coordinate) {

    int x = (int)(coordinate.x/(*scaleValue));
    int y = (int)(coordinate.y/(*scaleValue));

    return {x,y};
}

VCoord UIManager::Virtualize(sf::Vector2i coordinate) {

    int x = (int)((float)coordinate.x/(*scaleValue));
    int y = (int)((float)coordinate.y/(*scaleValue));

    return {x,y};
}