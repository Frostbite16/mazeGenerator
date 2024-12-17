//
// Created by guilherme on 04/12/24.
//

#ifndef CELLMAZE_H
#define CELLMAZE_H
#include<array>

    struct cell_node {
        std::array<bool, 4> walls;
        bool visited;
    };

#endif //CELLMAZE_H
