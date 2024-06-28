class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch in ('(', '{', '['):
                stack.append(ch)
                continue
            
            try:
                p = stack.pop()
            except IndexError:
                return False
            else:
                if (
                    (ch == ')' and p != '(')
                    or (ch == '}' and p != '{')
                    or (ch == ']' and p != '[')
                ):
                    return False

        return len(stack) == 0
