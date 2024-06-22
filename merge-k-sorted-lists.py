from __future__ import annotations
from typing import List, Any, Optional

class ListNode:
    def __init__(self, val: Any = 0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]

        mid = len(lists) // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])
        return self.merge(left, right)

    def merge(self, list1: ListNode, list2: ListNode) -> ListNode:
        dummy = ListNode()
        ptr = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                ptr.next = list1
                list1 = list1.next
            else:
                ptr.next = list2
                list2 = list2.next
            ptr = ptr.next

        ptr.next = list1 or list2
        return dummy.next

