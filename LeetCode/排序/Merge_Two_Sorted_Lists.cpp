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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode dummy(-1);
        ListNode *ptr = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if (l1 == NULL)
            ptr->next = l2;
        else
            ptr->next = l1;
        
        return dummy.next;
    }
};
