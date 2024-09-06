# 3217. Delete Nodes From Linked List Present in Array
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        remove=set(nums)
        def delete(curr):
            if curr is None:
                return None
            if curr.val in remove:
                return delete(curr.next)
            curr.next=delete(curr.next)
            return curr
        head=delete(head)
        return head