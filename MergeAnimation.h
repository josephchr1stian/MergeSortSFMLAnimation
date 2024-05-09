//
// Created by Joseph Garcia on 5/8/24.
//
#ifndef SORTANIMATION_MERGEANIMATION_H
#define SORTANIMATION_MERGEANIMATION_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <stack>

class MergeAnimation: public sf::Drawable
{
private:

    sf::Clock clock;
    std::vector<sf::RectangleShape> rects;
    std::vector<int> nums;
    int toDo = 0;
    int arrayInt[300];
    bool unsorted = true;
    sf::Vector2f pos = {10,420};

public:
    MergeAnimation();
    void update();
    void merge(int data[], int size, int size2) const;
    void mergeSortAlgo(int data[], int size) const;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override ;
};


#endif //SORTANIMATION_MERGEANIMATION_H
