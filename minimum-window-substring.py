class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "": return ""

        target = {}
        window = {}

        for ch in t:
            target[ch] = 1 + target.get(ch, 0)

        have, need = 0, len(target)
        ans, length = [-1, -1], float("inf")
        left = 0

        for right in range(len(s)):
            ch = s[right]
            window[ch] = 1 + window.get(ch, 0)

            if ch in target and window[ch] == target[ch]:
                have += 1

            while have == need:
                if (right-left+1) < length:
                    ans = [left, right]
                    length = right - left + 1

                window[s[left]] -= 1
                if s[left] in target and window[s[left]] < target[s[left]]:
                    have -= 1
                left += 1

        left, right = ans
        return s[left:right+1] if length != float("inf") else ""
