from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])

        def match(r: int, c: int, i: int) -> bool:
            if i == len(word):
                return True
            if r not in range(rows) or c not in range(cols):
                return False
            
            ch = board[r][c]
            board[r][c] = ""
            if (word[i] == ch
                and (
                    match(r+1, c, i+1)
                    or match(r, c+1, i+1)
                    or match(r-1, c, i+1)
                    or match(r, c-1, i+1)
                )
            ):
                return True
            board[r][c] = ch
            return False
        
        for r in range(rows):
            for c  in range(cols):
                if word[0] == board[r][c] and match(r, c, 0):
                    return True
        return False
