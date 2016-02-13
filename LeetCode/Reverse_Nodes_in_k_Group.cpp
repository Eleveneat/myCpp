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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
            
            ListNode *next_group = head;
            for (int i = 0; i < k; i++) {
                if (next_group)
                    next_group = next_group->next;
                else
                    return head;
            }
            // next_group is the head of next group
            // new_next_group  is the new head of next group after reversion
            ListNode *new_next_group = reverseKGroup(next_group, k);
            ListNode *prev = NULL, *cur = head;
            while (cur != next_group) {
                ListNode *next = cur->next;
                cur->next = prev ? prev : new_next_group;
                prev = cur;
                cur = next;
            }
            return prev; // prev will be the new head of this group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        for (ListNode *prev = &dummy, *end = head; end; end = prev->next) {
            for (int i =  1; i < k && end; i++) 
                end = end->next;
            if (end == nullptr)
                break;
            prev = reverse(prev, prev->next, end);
        }
        return dummy.next;
    }
private:
    ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
        ListNode *end_next = end->next;
        for (ListNode *p = begin, *cur = p->next, *next = cur->next; cur != end_next; p = cur, cur = next, next = next ? next->next : nullptr) {
            cur->next = p;
        }
        
        begin->next = end_next;
        prev->next = end;
        return begin;
    }
};
