from __future__ import annotations
from typing import Optional, Any


class ListNode:
    def __init__(self, val: Any = 0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        ptr = dummy

        while list1 and list2:
            if list2.val < list1.val:
                ptr.next = list2
                list2 = list2.next
            else:
                ptr.next = list1
                list1 = list1.next
            ptr = ptr.next

        if list1:
            ptr.next = list1

        if list2:
            ptr.next = list2

        return dummy.next

