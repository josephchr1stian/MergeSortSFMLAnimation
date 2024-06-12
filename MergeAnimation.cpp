//
// Created by Joseph Garcia on 5/8/24.
//

#include "MergeAnimation.h"

MergeAnimation::MergeAnimation()
{
    sf::RectangleShape rect({3, 100});
    rect.setFillColor(sf::Color::White);
    rect.rotate(180);
    sf::Vector2f locPos = {10,420};
    for( int i = 0; i < 300; i++)
    {
        int newVal = rand()%400;
        nums.push_back(newVal);
        rect.setSize({rect.getSize().x, static_cast<float>(newVal)});
        rect.setPosition(locPos);
        locPos.x +=3;
        rects.push_back(rect);
    }

}

void MergeAnimation::update()
{
    if (unsorted)
    {
        int arrSize = sizeof(arrayInt) / sizeof(arrayInt[0]);
        for(int i = 0; i < 300; i++)
        {
            arrayInt[i] = nums[i]; //Copy all the ints, sort the array
        }
        mergeSortAlgo(arrayInt, arrSize);
        unsorted = false; // Now its sorted
    }
    if(toDo < 300) // Change one by  one
    {
        sf::sleep(sf::seconds(0.01));
        rects[toDo].setSize({rects[toDo].getSize().x, static_cast<float>(arrayInt[toDo])});
        rects[toDo].setPosition(pos);
        pos.x +=3;
        toDo++;
        return;
    }
}

void MergeAnimation::merge(int data[], int size, int size2) const
{
    int *temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int i;

    temp =  new int[size + size2];
    while( (copied1 < size) && (copied2 < size2)) //While not everything has been copied, copied1 + copied2 < size
    {
        if(data[copied1] < (data+ size)[copied2])
            temp[copied++] = data[copied1++]; // we have to increment both variables, we can do it all in one line using the post fix ++
        else
            temp[copied++] = (data+ size)[copied2++];
    }
    while(copied1< size)
        temp[copied++] = data[copied1++];
    while (copied2 < size2)
        temp[copied++] = (data+size)[copied2++];

    for( i = 0; i < size + size2; ++i)
        data[i]=temp[i];

    delete[] temp;

}

void MergeAnimation::mergeSortAlgo(int data[], int size) const
{

    int n1, n2; //left size, right size
    if (size > 1) // Cut in half
    {
        n1 = size / 2;
        n2 = size - n1;
        mergeSortAlgo(data, n1);
        mergeSortAlgo((data + n1), n2);
        merge(data, n1, n2);
    }
}

void MergeAnimation::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < rects.size(); i++)
    {
        window.draw(rects[i]);
    }

}