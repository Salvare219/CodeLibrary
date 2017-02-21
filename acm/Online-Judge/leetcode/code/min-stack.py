# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        if head==None:
            return head
        p1=p2=head
        las=None
        n-=1
        while n:
            p2=p2.next
            n-=1
        while p2.next!=None:
            p2=p2.next
            las=p1
            p1=p1.next
        if las!=None:
            las.next=p1.next
            return head
        else:
            return p1.next
        
        