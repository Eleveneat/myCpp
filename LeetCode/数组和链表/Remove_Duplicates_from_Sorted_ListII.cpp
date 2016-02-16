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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head, *next = head->next;
        for (; cur; cur = prev->next) {
            next = cur->next;
            if (next == nullptr)
                break;
            if (cur->val != next->val) {
                prev = cur;
            } else {
                while (next && next->val == cur->val) {
                    ListNode *deleteNode = next;
                    next = next->next;
                    delete deleteNode;
                }
                delete cur;
                prev->next = next;
            }
        }
        return dummy.next;
    }
};
