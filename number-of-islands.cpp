#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int, int>> visited;
        int islands = 0;

        for (int r=0; r<rows; ++r) {
            for (int c=0; c<cols; ++c) {
                pair<int, int> p(r, c);
                if (grid[r][c] == '1' and visited.count(p) == 0) {
                    bfs(r, c, visited, grid);
                    ++islands;
                }
            }
        }

        return islands;
    }

    void bfs(int row, int col, set<pair<int, int>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        q.push(pair<int, int>(row, col));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for (vector<int> dir: dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                pair<int, int> np(nr, nc);

                if (
                    (0 <= nr)
                    && (nr < rows)
                    && (0 <= nc)
                    && (nc < cols)
                    && (grid[nr][nc] == '1')
                    && (visited.count(np) == 0)
                ) {
                    q.push(np);
                    visited.insert(np);
                }
            }
        }
    }
};
