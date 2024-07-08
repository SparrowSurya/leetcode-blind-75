from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for _ in range(len(nums)+1)]

        for n in nums:
            count[n] = 1 + count.get(n, 0)

        for num, cnt in count.items():
            freq[cnt].append(num)

        ans = []
        for num_list in reversed(freq):
            for num in num_list:
                ans.append(num)
                if len(ans) == k: return ans
        return ans
