#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int, int>> edges) {
        unordered_map<int, vector<int>> graph;
        
        for (int i=0; i<n; ++i) {
            graph[i] = vector<int>();
        }

        for (vector<int> v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        unordered_set<int> visited;
        int count = 0;
        for (auto p: graph) {
            if (visited[p.first]) {
                continue;
            }
            count += 1;
            visit(p.first, -1, graph, visited);
        }
        return count;
    }

    void visit(int node, int prev, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (visited.find(node) != visited.end()) {
            return;
        }

        visited.insert(node);
        for (int adj: graph[node]) {
            visit(adj, node, graph, visited)
        }

        return true;
    }
};
