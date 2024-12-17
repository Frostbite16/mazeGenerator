#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H
#include "CellMaze.h"
#include <vector>

extern const std::size_t nodeQuantX;
extern const std::size_t nodeQuantY;

class MazeGraph{
	std::vector<std::vector<struct cell_node>> cells; // Vector matrix of cells
	public:
		MazeGraph();
		cell_node* returnCell(std::pair<std::size_t, std::size_t> index); // return pointer to a cell at a specific location
		void addWall(std::pair<std::size_t,std::size_t> index, short direction);  // Specify a location and adding a wall into direction starting at 0 (north) and going clockwise until it ends at 3 (west)
		void removeWall(std::pair<std::size_t,std::size_t> index, short direction); // Specify a location and removing a wall into direction starting at 0 (north) and going clockwise until it ends at 3 (west)
	};
#endif
