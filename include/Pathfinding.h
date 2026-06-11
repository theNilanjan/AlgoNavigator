#pragma once

#include <vector>

class Pathfinding
{
public:
    static bool BFS(
        std::vector<std::vector<int>>& grid,
        int startRow,
        int startCol,
        int endRow,
        int endCol
    );
};