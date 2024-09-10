# 2807. Insert Greatest Common Divisors in Linked List
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def gcd(a, b):
            if a<b:
                a,b=b,a
            while b:
                a,b=b,a%b
            return a
        
        curr=head
        while curr and curr.next:
            new=ListNode(gcd(curr.val, curr.next.val), curr.next)
            curr.next=new
            curr=curr.next.next

        return head