from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        return "".join(str(len(s)) + "#" + s for s  in strs)

    def decode(self, string: str) -> List[str]:
        ans = []
        i = 0

        while i < len(string):
            j = i
            while string[j].isdigit():
                j += 1

            length = str(string[i:j])
            ans.append(string[j+1:j+1+length])
            i = j + 1 + length

        return ans
