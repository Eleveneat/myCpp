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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *next = head->next, *prev = nullptr;
        while (head != nullptr) {
            head->next = prev;
            prev = head;
            head = next;
            if (next != nullptr)
                next = next->next;
        }
        return prev;
    }
};


