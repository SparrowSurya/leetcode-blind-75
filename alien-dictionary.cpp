#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string> words) {
        unordered_map<char, unordered_set<char>> hashmap;

        for (int i=0; i < words.size()-1; ++i) {
            string w1 = words[i];
            string w2 = words[i+1];
            int min_len = min(w1.size(), w2.size());

            if ((w1 > w2) && (w1.substr(0, min_len) == w2.substr(0, min_len))) {
                return string();
            }

            for (int j=0; j<min_len; ++j) {
                if (w1[j] != w2[j]) {
                    if (hashmap.find(w1[j]) == hashmap.end()) {
                        hashmap[w1[j]] = unordered_set<char>();
                    }
                    hashmap[w1[j]].insert(w2[j]);
                }
            }
        }

        string ans;
        unordered_map<char, bool> visited;
        
        for (auto item: hashmap) {
            if (dfs(item.first, visited, hashmap, ans)) {
                return string();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfs(char c, unordered_map<char, bool>& visited, unordered_map<char, unordered_set<char>>& hashmap, string& ans) {
        if (visited.find(c) != visited.end()) {
            return visited[c];
        }

        visited[c] = true;
        for (char next: hashmap[c]) {
            if (dfs(next, visited, hashmap, ans)) {
                return true;
            }
        }

        visited[c] = false;
        ans.push_back(c);
        return false;
    }
};
