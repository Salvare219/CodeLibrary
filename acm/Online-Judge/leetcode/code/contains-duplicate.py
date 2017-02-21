# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        if head==None or head.next==None:
            return True
        if head.next.next==None:
            return head.val==head.next.val
        p1=p2=head
        las=None
        while p2.next!=None and p2.next.next!=None:
            p2=p2.next.next
            t=p1.next
            p1.next=las
            las=p1
            p1=t
        if p2.next!=None:
            if p1.val!=p1.next.val:
                return False
            p1=p1.next.next
        else:
            p1=p1.next
        while p1!=None:
            if p1.val!=las.val:
                return False
            p1=p1.next
            las=las.next
        return True
        