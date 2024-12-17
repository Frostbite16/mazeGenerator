//
// Created by guilherme on 05/12/24.
//

#ifndef DRAWMAZE_H
#define DRAWMAZE_H
#include<vector>
#include"../MazeLogic/CellMaze.h"
#include<SFML/Graphics.hpp>
#include<cmath>

extern const std::size_t nodeQuantX;
extern const std::size_t nodeQuantY;

extern const std::size_t SCREEN_SIZEX;
extern const std::size_t SCREEN_SIZEY;

struct cell{
    sf::Vector2u pos;
    cell_node* cellSource=nullptr;
};

class drawMaze {
    std::vector<std::vector<struct cell>> maze;
    unsigned int cellSizeX;
    unsigned int cellSizeY;

public:
    drawMaze();
    void updateCellSizes(sf::RenderWindow& window);
    void connectCellToSource(std::pair<std::size_t,std::size_t> index,cell_node* cellSource); // connect the graphical representation of a cell to a logic cell
    void drawAndUpdate(sf::RenderWindow& window);
};



#endif //DRAWMAZE_H
