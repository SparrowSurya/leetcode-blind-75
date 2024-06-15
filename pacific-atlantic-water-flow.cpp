#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pacific, atlantic;
        int rows = heights.size();
        int cols = heights[0].size();

        for (int r=0; r<rows; ++r) {
            dfs(r, 0, pacific, heights[r][0], heights);
            dfs(r, cols-1, atlantic, heights[r][cols-1], heights);
        }

        for (int c=0; c<cols; ++c) {
            dfs(0, c, pacific, heights[0][c], heights);
            dfs(rows-1, c, atlantic, heights[rows-1][c], heights);
        }

        vector<vector<int>> common;
        for (int r=0; r<rows; ++r) {
            for (int c=0; c<cols; ++c) {
                pair<int, int> p(r, c);
                if (pacific.count(p)>0 and atlantic.count(p)>0) {
                    vector<int> v = {r, c};
                    common.push_back(v);
                }
            }
        }

        return common;
    }

    void dfs(int r, int c, set<pair<int, int>>& visited, int prev_height, vector<vector<int>>& heights) {
        pair<int, int> p(r, c);
        if (
            (r < 0) || (r >= heights.size()) || (c < 0) || (c >= heights[0].size())
            || (visited.count(p) != 0)
            || (heights[r][c] < prev_height)
        ) return;
        
        visited.insert(p);
        dfs(r-1, c, visited, heights[r][c], heights);
        dfs(r+1, c, visited, heights[r][c], heights);
        dfs(r, c-1, visited, heights[r][c], heights);
        dfs(r, c+1, visited, heights[r][c], heights);
    }
};
