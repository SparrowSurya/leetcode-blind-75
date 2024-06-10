class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        table = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]

        for i in range(len(text1) - 1, -1, -1):
            for j in range(len(text2) - 1, -1, -1):
                if text1[i] == text2[j]:
                    table[i][j] = 1 + table[i + 1][j + 1]
                else:
                    table[i][j] = max(table[i + 1][j], table[i][j + 1])

        return table[0][0]
