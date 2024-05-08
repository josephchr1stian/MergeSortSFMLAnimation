//
// Created by Joseph Garcia on 4/11/24.
//


#include "MouseEvents.h"
bool MouseEvents:: isHovered(const sf::FloatRect & bounds, const sf::RenderWindow& window)
{
    return bounds.contains((sf::Vector2f)sf::Mouse::getPosition(window));

}


bool MouseEvents:: isClicked(const sf::FloatRect & bounds, const sf::RenderWindow& window, const sf::Event & event)

{
    if (bounds.contains((sf::Vector2f )sf::Mouse::getPosition(window)))
        return (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left);

    //return (event.type == sf::Event::MouseLeft && bounds.contains((sf::Vector2f )sf::Mouse::getPosition(window)));


}