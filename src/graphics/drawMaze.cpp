//
// Created by guilherme on 05/12/24.
//

#include "drawMaze.h"

drawMaze::drawMaze() {
    maze.resize(nodeQuantX);
    for (auto& cellRow : maze) {
        cellRow.resize(nodeQuantY);
    }
    // Calculating the size of each cell to fit the screen
    const unsigned int cellQuantity = nodeQuantX * nodeQuantY;
    const unsigned int columnMin = ceil(sqrt(cellQuantity));
    const unsigned int rowMin = ceil(cellQuantity / static_cast<double>(columnMin));

    /*
    cellSizeX = SCREEN_SIZEX / columnMin;
    cellSizeY = SCREEN_SIZEY / rowMin;
    */

    // If it works remove cell size for x and y
    cellSizeX = std::min(SCREEN_SIZEX/columnMin, SCREEN_SIZEY/rowMin);
    cellSizeY = cellSizeX;

    unsigned int currentPosX=0;
    unsigned int currentPosY=0;

    for (auto& cellRow : maze) {
        for (auto& cell : cellRow) {
            cell.pos.x = currentPosX*cellSizeX;
            cell.pos.y = currentPosY*cellSizeX;
            currentPosY++;
        }
        currentPosX++;
        currentPosY = 0;
    }
}

void drawMaze::updateCellSizes(sf::RenderWindow& window) {

    sf::Vector2u windowSizes = window.getSize();
    const unsigned int cellQuantity = nodeQuantX * nodeQuantY;
    const unsigned int columnMin = ceil(sqrt(cellQuantity));
    const unsigned int rowMin = ceil(cellQuantity / static_cast<double>(columnMin));

    /*cellSizeX = windowSizes.x / columnMin;
    cellSizeY = windowSizes.y / rowMin;*/ // Not perfect squares, but it fills the screen, kinda buggy sometimes

    cellSizeX = std::min(windowSizes.x/columnMin, windowSizes.y/rowMin);
    cellSizeY = cellSizeX;

}


void drawMaze::connectCellToSource(std::pair<std::size_t, std::size_t> index, cell_node *cellSource) {
    maze[index.first][index.second].cellSource = cellSource;
}

void drawMaze::drawAndUpdate(sf::RenderWindow& window){
    if(window.isOpen()){
        unsigned int wallGap = 1;

        short int direction = 0;
        sf::RectangleShape cellShape;
        cellShape.setSize(sf::Vector2f(cellSizeX-2*wallGap, cellSizeY-2*wallGap));
        sf::RectangleShape wall;
        //cellShape.setFillColor(sf::Color::White);

        for (auto& cellRow : maze){
            for (auto& cell : cellRow){
                direction = 0;
                for (auto& walls : cell.cellSource->walls) { // iterate to each cell wall
                    // These conditionals verify each direction the wall is facing and set the size and position accordingly
                    if(direction == 0 || direction == 2){
                        wall.setSize(sf::Vector2f(cellSizeX + wallGap, wallGap));

                        if (direction == 0) {
                            wall.setPosition(cell.pos.x, cell.pos.y);
                            //wall.setFillColor(sf::Color::Red);
                        }
                        else {
                            wall.setPosition(cell.pos.x, cell.pos.y+cellSizeY-wallGap);
                            //wall.setFillColor(sf::Color::Green);
                        }
                    }
                    else{
                        wall.setSize(sf::Vector2f(wallGap, cellSizeY + wallGap));
                        if (direction == 1) {
                            wall.setPosition(cell.pos.x + cellSizeX - wallGap, cell.pos.y);
                            //wall.setFillColor(sf::Color::Blue);
                        }
                        else {
                            wall.setPosition(cell.pos.x, cell.pos.y);
                            //wall.setFillColor(sf::Color::White);
                        }
                    }

                    if(walls){
                        wall.setFillColor(sf::Color::White);
                    }
                    else {
                        sf::Color color(0,0,0);
                        color.a = 0;
                        wall.setFillColor(color);
                    }
                    window.draw(wall);

                    direction++;


                }

                // Just for viewing which cell the algorith has already visited
                if (cell.cellSource->visited) cellShape.setFillColor(sf::Color::Green);
                else cellShape.setFillColor(sf::Color::Black);

                cellShape.setPosition(sf::Vector2f(cell.pos.x + wallGap, cell.pos.y + wallGap));
                window.draw(cellShape);

            }
        }

    }

}



