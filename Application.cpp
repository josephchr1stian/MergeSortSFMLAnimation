//
// Created by Joseph Garcia on 4/10/24.
//

#include "Application.h"
#include "MouseEvents.h"
#include "MergeAnimation.h"

void Application::run()
{
    MergeAnimation merger;
    sf::RenderWindow window({720, 420, 32}, "merge sort");
    sf::Text words;

    words.setString("Hello");
    words.setCharacterSize(24);
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)

                window.close();
            merger.update();
        }

        window.clear();//window.draw(words);
        //for(Text & t: textVector)
        //window.draw(t);
        window.draw(merger);
        window.display();
    }
}
