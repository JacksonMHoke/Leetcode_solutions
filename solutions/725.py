# 725. Split Linked List in Parts
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0
        curr = head
        while curr:
            n += 1
            curr = curr.next
        
        groupSize = n//k
        extras = n%k if groupSize>0 else 0

        curr = head
        rt = []
        i = 0
        while curr:
            rt.append(curr)
            for i in range(groupSize-1):
                curr = curr.next
            if extras:
                extras -= 1
                curr = curr.next

            if curr is None:
                break
            
            temp = curr.next
            curr.next = None
            curr = temp
            i += 1
        while len(rt)<k:
            rt.append(None)
        return rt

