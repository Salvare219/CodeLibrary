# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def mergeTwoLists(self, l1, l2):
        if l1==None:
            return l2
        f=l1
        while l2!=None:
            while l1!=None and l1.next!=None and l1.next.val<l2.val:
                l1=l1.next
            if l1.val<l2.val:
                t=l2.next
                l2.next=l1.next
                l1.next=l2
                l2=t
            else:
                f=l2
                t=l2.next
                l2.next=l1
                l2=t
                l1=f
        return f