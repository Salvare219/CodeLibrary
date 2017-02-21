# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        if head==None:
            return head
        now=head
        while now.next!=None:
            las=now.next
            while las!=None and now.val==las.val:
                las=las.next
            now.next=las
            now=las
            if now==None:
                return head
        return head
        