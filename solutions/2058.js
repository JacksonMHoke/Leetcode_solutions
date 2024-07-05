// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

function isCritical(a, b, c) {
    return (b-a)*(b-c)>0;
}

/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function(head) {
    let rt=[100001, -1];
    let first=Number.MAX_SAFE_INTEGER, i=1, prevCritical=-100001;
    let next=head.next.next, curr=head.next, prev=head;
    while (next!=null) {
        while (next!=null && !isCritical(prev.val, curr.val, next.val)) {
            next=next.next;
            curr=curr.next;
            prev=prev.next;
            i++;
        }
        if (next==null)
            break;
        first=Math.min(first, i);
        rt[0]=Math.min(i-prevCritical, rt[0]);
        rt[1]=i;
        prevCritical=i;

        next=next.next;
        curr=curr.next;
        prev=prev.next;
        i++;
    }

    if (rt[0]==100001)
        return [-1, -1];

    rt[1]-=first;
    return rt;
};