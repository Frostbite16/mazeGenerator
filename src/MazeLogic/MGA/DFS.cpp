//
// Created by guilherme on 22/12/24.
//

#include "DFS.h"

DFS::DFS(MazeGraph* maze): MazeInteraction(maze) {
    cellStack.push(this->getCurrentCell());
}

bool DFS::step() {
    if (maze && !cellStack.empty()) {
        std::pair<std::size_t, std::size_t> currentCell = cellStack.top();
        short check = 0;
        std::vector<directions> excluded;

        // generate random number
        std::random_device rng;
        std::mt19937 gen(rng());
        std:: uniform_int_distribution<int> dist(0,3);
        directions randomNumber = static_cast<directions>(dist(gen));
        while (check <= 3 && check != -1) {
            while (!excluded.empty() && std::find(excluded.begin(), excluded.end(), randomNumber) != excluded.end())
                randomNumber = static_cast<directions>(dist(gen));
            switch (randomNumber) {
                case UP:
                    if (currentCell.second != 0 && !this->maze->returnCell({currentCell.first, currentCell.second-1})->visited) {
                        this->maze->removeWall(currentCell,UP);
                        this->goToDirection(UP);
                        cellStack.push(this->getCurrentCell());
                        check = -1;
                    }
                    else {
                        excluded.push_back(randomNumber);
                        check++;
                    }
                break;
                case DOWN:
                    if (bool value = (currentCell.second < nodeQuantY-1 && !this->maze->returnCell({currentCell.first, currentCell.second+1})->visited)) {

                        this->maze->removeWall(currentCell,DOWN);
                        this->goToDirection(DOWN);
                        cellStack.push(this->getCurrentCell());
                        check = -1;
                    }
                    else {
                        excluded.push_back(randomNumber);
                        check++;
                    }
                break;

                case LEFT:
                    if (currentCell.first != 0 && !this->maze->returnCell({currentCell.first-1, currentCell.second})->visited) {
                        this->maze->removeWall(currentCell,LEFT);
                        this->goToDirection(LEFT);
                        cellStack.push(this->getCurrentCell());
                        check = -1;
                    }
                    else {
                        excluded.push_back(randomNumber);
                        check++;
                    }
                break;
                case RIGHT:
                    if (currentCell.first < nodeQuantX-1 && !this->maze->returnCell({currentCell.first+1, currentCell.second})->visited) {
                        this->maze->removeWall(currentCell,RIGHT);
                        this->goToDirection(RIGHT);
                        cellStack.push(this->getCurrentCell());
                        check = -1;
                    }
                    else {
                        excluded.push_back(randomNumber);
                        check++;
                    }
                break;
                default:
                    break;
            }

        }
        if (check == -1) {
            return true;
        }
    }
    cellStack.pop();
    if (cellStack.empty()) {
        return false;
    }
    this->setCurrentCell(cellStack.top());
    return true;
}

