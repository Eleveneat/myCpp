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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t len = 0;
        for (ListNode *p = head; p; p = p->next)
            len++;
        n = len - n;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while (n--) {
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        return dummy.next;
    }
};
//注意要one pass，即一次循环中通过。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //ListNode dummy{-1, head};
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;
        
        for (int i = 0; i < n; i++)
            q = q->next;
        
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};
