# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        if head==None:
            return None
        tp=head
        las=None
        while head!=None:
            if head.val==val:
                if las==None:
                    tp=head.next
                else:
                    las.next=head.next
            else:
                las=head
            head=head.next
        return tp
            
        