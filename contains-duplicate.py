from typing import Dict, List

"""
Approaches
1. compare every two elements
2. sort
3. hashmap
"""


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashmap: Dict[int, int] = {}
        for num in nums:
            value = hashmap.get(num, 0)
            if value > 0:
                return True
            hashmap[num] = value + 1
        return False
