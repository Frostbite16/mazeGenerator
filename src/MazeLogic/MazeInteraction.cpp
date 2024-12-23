//
// Created by guilherme on 22/12/24.
//

#include "MazeInteraction.h"

#include <iostream>
#include <ostream>


MazeInteraction::MazeInteraction(MazeGraph* maze): currentCell({0,0}), maze(maze) {
    maze->returnCell({0,0})->visited = true;
}

void MazeInteraction::goToCell(std::pair<std::size_t, std::size_t> cell) {
    try {
        if (cell.first >= nodeQuantX || cell.second >= nodeQuantY || cell.first < 0 || cell.second < 0) {
            throw(std::runtime_error("MazeInteraction::goToCell: Out of bounds"));
        }
        currentCell = cell;
    }
    catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    maze->returnCell(currentCell)->visited = true;
}

void MazeInteraction::goToDirection(directions direction) {
    switch (direction) {
        case UP:
            if (currentCell.second == 0)
                throw(std::runtime_error("MazeInteraction::goToDirection: Direction out of bounds"));
            if (maze->returnCell(currentCell)->walls[UP] != true)
                currentCell.second--;
            break;
        case DOWN:
            if (currentCell.second > nodeQuantY-1)
                throw(std::runtime_error("MazeInteraction::goToDirection: Direction out of bounds"));
            if (maze->returnCell(currentCell)->walls[DOWN] != true)
                currentCell.second++;
            break;
        case RIGHT:
            if (currentCell.first == nodeQuantX-1)
                throw(std::runtime_error("MazeInteraction::goToDirection: Direction out of bounds"));
            if (maze->returnCell(currentCell)->walls[RIGHT] != true)
                currentCell.first++;
            break;
        case LEFT:
            if (currentCell.first == 0)
                throw(std::runtime_error("MazeInteraction::goToDirection: Direction out of bounds"));
            if (maze->returnCell(currentCell)->walls[LEFT] != true)
                currentCell.first--;
            break;
    }
    maze->returnCell(currentCell)->visited = true;
}

std::pair<std::size_t, std::size_t> MazeInteraction::getCurrentCell() {
    return currentCell;
}

void MazeInteraction::setCurrentCell(std::pair<std::size_t, std::size_t> cell) {
    currentCell = cell;
}