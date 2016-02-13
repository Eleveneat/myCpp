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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        //ListNode *a, *b, *c = &dummy;
        for (ListNode *a, *b, *c = &dummy; c->next && c->next->next; ) {
            a = c;
            b = c->next;
            c = c->next->next;
            a->next = c;
            b->next = c->next;
            c->next = b;
            c = b;
        }
        return dummy.next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; next; prev = cur, cur = cur->next, next = cur ? cur->next : nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};
