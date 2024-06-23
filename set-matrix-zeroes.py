from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        rflag, cflag = False, False

        for r in range(rows):
            if matrix[r][0] == 0:
                cflag = True
                break
        
        for c in range(cols):
            if matrix[0][c] == 0:
                rflag = True
                break

        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    matrix[r][0] = 0

        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0

        if rflag:
            for c in range(cols):
                matrix[0][c] = 0

        if cflag:
            for r in range(rows):
                matrix[r][0] = 0
