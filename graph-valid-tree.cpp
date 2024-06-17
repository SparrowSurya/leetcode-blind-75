#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int, int>> edges) {
        unordered_map<int, vector<int>> graph;
        
        for (int i=0; i<n; ++i) {
            graph[i] = vector<int>();
        }

        for (vector<int> v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        unordered_set<int> visited;
        return isTree(0, -1, graph, visited) and visited.size() == n;
    }

    bool isTree(int node, int prev, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (visited.find(node) != visited.end()) {
            return false;
        }

        visited.insert(node);
        for (int adj: graph[node]) {
            if (adj == prev) {
                continue;
            }
            if (!isTree(adj, node, graph, visited)) {
                return false;
            }
        }

        return true;
    }
};
