/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 擦，没留意是sorted list...时间复杂度是可以O(n)的。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode *a = head; a; a = a->next) {
            int val = a->val;
            for (ListNode *b = a; b; b = b->next) {
                while (b->next && b->next->val == val) {
                    b->next = b->next->next;
                }
            }
        }
        
        return head;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        
        for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
        }
        return head;
    }
};
