#include "../include/Pathfinding.h"

#include <queue>
#include <vector>

bool Pathfinding::BFS(
    std::vector<std::vector<int>>& grid,
    int startRow,
    int startCol,
    int endRow,
    int endCol
)
{
    int rows = grid.size();
    int cols = grid[0].size();

    std::queue<std::pair<int,int>> q;

    std::vector<std::vector<bool>> visited(
        rows,
        std::vector<bool>(cols,false)
    );

    q.push({startRow,startCol});
    visited[startRow][startCol] = true;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        if(r == endRow && c == endCol)
            return true;

        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 &&
               nr < rows &&
               nc >= 0 &&
               nc < cols &&
               !visited[nr][nc] &&
               grid[nr][nc] != 1)
            {
                visited[nr][nc] = true;

                if(grid[nr][nc] == 0)
                    grid[nr][nc] = 4;

                q.push({nr,nc});
            }
        }
    }

    return false;
}