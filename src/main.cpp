#include <SFML/Graphics.hpp>
#include "MazeLogic/MazeGraph.h"
#include "graphics/drawMaze.h"
#include "MazeLogic/MazeInteraction.h"
#include "MazeLogic/MGA/DFS.h"

const std::size_t nodeQuantX = 20;
const std::size_t nodeQuantY = 20;

const std::size_t SCREEN_SIZEX = 800;
const std::size_t SCREEN_SIZEY = 800;

int main()
{
    MazeGraph maze;
    drawMaze graphicManager;
    DFS DFSalgo(&maze);
    bool generating = true;

    // Subroutine to link logic cells to graphic cells
    for (std::size_t x = 0; x < nodeQuantX; x++) {
        for (std::size_t y = 0; y < nodeQuantY; y++) {
            graphicManager.connectCellToSource({x,y}, maze.returnCell({x,y}));
        }
    }

    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZEX, SCREEN_SIZEY), "Maze", sf::Style::Default);

    //window.setFramerateLimit(5);

    /*sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(30, 30));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(0,0);*/
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        // check all the window's events that were triggered since the last iteration of the loop
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        window.clear();
        graphicManager.updateCellSizes(window);
        graphicManager.drawAndUpdate(window);
        window.display();
        if(generating)
            generating = DFSalgo.step();


    }

    return 0;
}