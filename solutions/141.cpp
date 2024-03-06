// 141. Linked List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *fast=head, *slow=head;
        while (true) {
            if (fast) fast = fast->next;
            if (fast) fast = fast->next;
            else return false;

            if (slow) slow = slow->next;
            else return false;

            if (slow==fast) return true;
        }
    }
};