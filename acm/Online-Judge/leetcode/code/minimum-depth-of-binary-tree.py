# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def cir(self,head):
        if head==None:
            return None
        p1=p2=head
        while p2.next!=None and p2.next.next!=None:
            p2=p2.next.next
            p1=p1.next
            if p1==p2:
                break
        if p2.next==None or p2.next.next==None:
            return None
        while head!=p1:
            head=head.next
            p1=p1.next
        return p1
    def getIntersectionNode(self, headA, headB):
        tail=headA
        if tail==None:
            return None
        while tail.next!=None:
            tail=tail.next
        tail.next=headA
        ans=self.cir(headB)
        tail.next=None
        return ans
        
        
        