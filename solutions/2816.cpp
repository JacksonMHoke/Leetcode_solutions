// 2816. Double a Number Represented as a Linked List
class Solution {
public:
    int helper(ListNode* head) {
        if (!head)
            return 0;
        int carryOver=helper(head->next);
        int newVal=head->val*2+carryOver;
        head->val=newVal%10;
        return newVal/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carryOver=helper(head);
        if (carryOver) {
            ListNode* newHead=new ListNode(carryOver);
            newHead->next=head;
            head=newHead;
        }
        return head;
    }
};