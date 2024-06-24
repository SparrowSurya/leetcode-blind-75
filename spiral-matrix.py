from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []

        minrows, mincols = 0, 0
        maxrows, maxcols = len(matrix), len(matrix[0])
        count = maxrows * maxcols
        r, c = 0, -1

        dirs = (0, 1), (1, 0), (0, -1), (-1, 0)
        d = 0

        while count > 0:
            nr, nc = r + dirs[d][0], c + dirs[d][1]

            if nr in range(minrows, maxrows) and nc in range(mincols, maxcols):
                ans.append(matrix[nr][nc])
                r, c = nr, nc
                count -= 1

            else:

                if d == 0:
                    minrows += 1
                elif d == 1:
                    maxcols -= 1
                elif d == 2:
                    maxrows -= 1
                elif d == 3:
                    mincols += 1
                
                d = (d+1)%4

        return ans
