//
// Created by guilherme on 22/12/24.
//

#ifndef DFS_H
#define DFS_H
#include<stack>
#include<random>
#include<algorithm>
#include"../MazeInteraction.h"
#include"../../GU.cpp"


class DFS:MazeInteraction{
    std::stack<std::pair<std::size_t,std::size_t>> cellStack;
public:
    explicit DFS(MazeGraph* maze);
    bool step();
    // TODO: Implement Depth-first Search
};



#endif //DFS_H
