//
// Created by Joseph Garcia on 5/8/24.
//

#include "MergeAnimation.h"

MergeAnimation::MergeAnimation()
{
    int size = 300;
    int arr[size];
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    sf::RectangleShape rect({3, 100});
    rect.setFillColor(sf::Color::White);
    rect.rotate(180);

    sf::Vector2f pos = {10,420};

    for( int i = 0; i < size; i++)
    {
        int newVal = rand()%400;
        arr[i] = newVal;
        nums.push_back(newVal);
        rect.setSize({rect.getSize().x, static_cast<float>(newVal)});
        rect.setPosition(pos);
        pos.x +=3;
        rects.push_back(rect);
    }

}

void MergeAnimation::update()
{
    while(toDo < 300)
    {

    }
    sf::Vector2f pos = {10,420};

    int arrSize = sizeof(arrayInt) / sizeof(arrayInt[0]);
    for (int i = 0; i < 300; i++)
    {
        array[i] = nums[i];
    }
    mergeSortAlgo(arraInt, arrSize);
    for (int i = 0; i < 300; i++)
    {
        rects[i].setSize({rects[i].getSize().x, static_cast<float>(array[i])});
        rects[i].setPosition(pos);
        pos.x +=3;
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