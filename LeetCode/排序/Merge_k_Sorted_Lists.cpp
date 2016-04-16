/**超时
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        for (size_t i = 0; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
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

/** 归并思想
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int len = lists.size();
        if (len == 0)
            return NULL;
        if (len == 1)
            return lists[0];
        if (len == 2)
            return mergeTwoLists(lists[0], lists[1]);
        vector<ListNode*> v1;
        vector<ListNode*> v2;
        for (int i = 0; i < len / 2; i++) {
            v1.push_back(lists[i]);
        }
        
        for (int i = len / 2; i < len; i++) {
            v2.push_back(lists[i]);
        }
        
        ListNode *l1 = mergeKLists(v1);
        ListNode *l2 = mergeKLists(v2);
        return mergeTwoLists(l1, l2);
    }
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
