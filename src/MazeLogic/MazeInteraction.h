//
// Created by guilherme on 22/12/24.
//

#ifndef MAZEINTERACTION_H
#define MAZEINTERACTION_H
#include<utility>
#include<stdexcept>
#include"MazeGraph.h"
#include"../GU.cpp"

extern const std::size_t nodeQuantX;
extern const std::size_t nodeQuantY;

class MazeInteraction{
    std::pair<std::size_t,std::size_t> currentCell;
    protected:
        MazeGraph* maze = nullptr;
        void setCurrentCell(std::pair<std::size_t,std::size_t> cell);
    public:

        MazeInteraction(MazeGraph* maze);
        void goToCell(std::pair<std::size_t,std::size_t> cell);
        void goToDirection(directions direction);
        std::pair<std::size_t,std::size_t> getCurrentCell();
};



#endif //MAZEINTERACTION_H
