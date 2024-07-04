// 2181. Merge Nodes in Between Zeros
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var mergeNodes = function(head) {
    let curr=head;
    let prev=head;
    while (curr.next!=null) {
        curr=curr.next;
        let sum=0;
        while (curr!=null && curr.val!=0) {
            sum+=curr.val;
            curr=curr.next;
        }
        prev.val=sum;
        prev.next=(curr.next!=null) ? curr : null;
        prev=curr;
    }
    return head;
};