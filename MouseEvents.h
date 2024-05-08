//
// Created by Joseph Garcia on 4/11/24.
//
#ifndef SORTANIMATION_MOUSEEVENTS_H
#define SORTANIMATION_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"

class MouseEvents {
public :

    static bool  isHovered(const sf::FloatRect & bounds, const sf::RenderWindow& window);
    static bool isClicked(const sf::FloatRect & bounds, const sf::RenderWindow& window, const sf::Event & event);


};

#endif //GUI_LIBRARY_MOUSEEVENTS_H
