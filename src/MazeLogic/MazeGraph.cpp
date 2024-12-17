#include "MazeGraph.h"

#include <iostream>
#include <stdexcept>



MazeGraph::MazeGraph() {

    cells.resize(nodeQuantX);
    for (auto& cellRow : cells) {
        cellRow.resize(nodeQuantY);
    } // create the vector

    cells[0][0];
    for(auto& cellRow: cells) { // initialize each cell
        for(auto& cell: cellRow) {
            cell.walls[0] = true;
            cell.walls[1] = true;
            cell.walls[2] = true;
            cell.walls[3] = true;
            cell.visited = false;
        }
    }
}


/*
 *
 *      Directions:
 *          0
 *       3     1
 *          2
 *
 */

cell_node *MazeGraph::returnCell(std::pair<std::size_t, std::size_t> index) {
    return &cells[index.first][index.second];
}


void MazeGraph::addWall(std::pair<size_t, size_t> index, short direction) {
    try {
        if(index.first >= nodeQuantX || index.second >= nodeQuantY || direction > 3)
            throw std::out_of_range("MazeGraph::addWall: index out of range");
        cells[index.first][index.second].walls[direction] = true;

        if(direction == 0 && index.second != 0){
            cells[index.first][index.second-1].walls[2] = true;
        }
        else if(direction == 1 && index.first < nodeQuantX-1) {
            cells[index.first+1][index.second].walls[3] = true;
        }
        else if(direction == 2 && index.second < nodeQuantY-1) {
            cells[index.first][index.second+1].walls[0] = true;
        }
        else if(direction == 3 && index.first != 0) {
            cells[index.first-1][index.second].walls[1] = true;
        }

    }catch(std::out_of_range) {
        std::cout << "MazeGraph::addWall: index out of range" << std::endl;
    }
}

void MazeGraph::removeWall(std::pair<size_t, size_t> index, short direction) {
    try {
        if(index.first > nodeQuantX || index.second > nodeQuantY || direction > 3)
            throw std::out_of_range("MazeGraph::addWall: index out of range");
        cells[index.first][index.second].walls[direction] = false;
        if(direction == 0 && index.second != 0){
            cells[index.first][index.second-1].walls[2] = false;
        }
        else if(direction == 1 && index.first < nodeQuantX-1) {
            cells[index.first+1][index.second].walls[3] = false;
        }
        else if(direction == 2 && index.second < nodeQuantY-1) {
            cells[index.first][index.second+1].walls[0] = false;
        }
        else if(direction == 3 && index.first != 0) {
            cells[index.first-1][index.second].walls[1] = false;
        }
    }catch(std::out_of_range) {
        std::cout << "MazeGraph::addWall: index out of range"<< std::endl;
    }
}
