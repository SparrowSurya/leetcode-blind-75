from __future__ import annotations
from typing import Optional, Any


class ListNode:
    def __init__(self, x: Any):
        self.val = x
        self.next: Optional[ListNode] = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head: return False
        if head.next is None: return False

        slow, fast = head, head.next
        while slow != fast and fast:
            if fast.next and fast.next.next:
                fast = fast.next.next
                slow = slow.next
            else:
                return False
        
        return fast is not None
