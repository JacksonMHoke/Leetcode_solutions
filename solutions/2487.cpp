// 2487. Remove Nodes From Linked List
class Solution {
public:
    int helper(ListNode* head) {
        if (!head)
            return 0;
        int max=helper(head->next);
        if (head->val<max) {
            ListNode* temp=head->next;
            *head=*head->next;
            delete temp;
            return max;
        }
        return head->val;
    }

    ListNode* removeNodes(ListNode* head) {
        helper(head);
        return head;
    }
};