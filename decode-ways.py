class Solution:
    def numDecodings(self, s: str) -> int:
        table = [0 for _ in range(len(s) + 1)]
        table[0] = 1

        if s[0] == "0":
            return 0
        else:
            table[1] = 1

        for i in range(2, len(s) + 1):
            if s[i - 1] != "0":
                table[i] += table[i - 1]
            if s[i - 2] == "1" or (s[i - 2] == "2" and s[i - 1] <= "6"):
                table[i] += table[i - 2]

        return table[len(s)]
