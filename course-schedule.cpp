#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hashmap;

        for (int i=0; i<numCourses; ++i) {
            hashmap[i] = vector<int>();
        }

        for (vector<int> pair: prerequisites) {
            hashmap[pair[0]].push_back(pair[1]);
        }

        vector<bool> visited(numCourses, false);
        for (int course=0; course < numCourses; ++course) {
            if (!finish(course, hashmap, visited)) return false;
        }
        return true;
    }

    bool finish(int course, unordered_map<int, vector<int>> hashmap, vector<bool> visited) {
        if (hashmap[course].size() == 0) return true;
        if (visited[course]) return false;

        visited[course] = true;
        for (int pre: hashmap[course]) {
            if (!finish(pre, hashmap, visited)) return false;
        }
        hashmap[course].clear();
        return true;
    }
};
