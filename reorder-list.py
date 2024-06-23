from __future__ import annotations
from typing import Any, Optional


class ListNode:
    def __init__(self, val: Any = 0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        global ptr

        if head is None or head.next is None:
            return None

        fast = slow = head
        while fast:
            try:
                fast = fast.next.next
                slow = slow.next
            except:
                break

        mid = slow
        ptr = head

        def dfs(node: Optional[ListNode]):
            global ptr

            if node is None:
                return

            dfs(node.next)

            ptr_next = ptr.next
            ptr.next = node
            node.next = ptr_next
            ptr = ptr_next

        dfs(mid.next)
        mid.next = None
