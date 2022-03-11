# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = slow
        slow = slow.next
        prev.next = None

        while slow:
            nextNode = slow.next
            slow.next = prev
            prev = slow
            slow = nextNode

        fast = prev
        slow = head

        while fast:
            if slow.val != fast.val:
                return False
            slow = slow.next
            fast = fast.next

        return True