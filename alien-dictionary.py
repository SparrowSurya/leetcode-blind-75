from typing import List

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        hashmap = {}

        for i in range(len(words)-1):
            w1, w2 = word[i], word[i+1]
            min_len = min(len(w1), len(w2))
            
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            
            for j in range(min_len):
                if w1[j] != w2[j]:
                    hashmap.get(w1[j], set()).add(w2[j])
                    break

        visited = {}
        ans = []
        
        def dfs(c: str):
            if c in visited:
                return visited[c]

            visited[c] = True
            for nxt in hashmap[c]:
                if dfs(nxt):
                    return True

            visited[c] = False
            ans.append(c)

        for c in hashmap:
            if dfs(c):
                return ""
        
        ans.reverse()
        return "".join(ans)
