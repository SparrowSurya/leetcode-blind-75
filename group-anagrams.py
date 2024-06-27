from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        sorted_strs = ["".join(sorted(s)) for s in strs]
        for s, ss in zip(strs, sorted_strs):
            try:
                groups[ss].append(s)
            except KeyError:
                groups[ss] = [s]
        return list(groups.values())
