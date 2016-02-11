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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return head;
        
        ListNode *aHead, *bHead, *aPtr, *bPtr;
        aHead = bHead = aPtr = bPtr = nullptr;
        while (head != nullptr) {
            if (head->val < x) {
                if (aHead == nullptr) {
                    aHead = aPtr = head;
                } else {
                    aPtr->next = head;
                    aPtr = head;
                }
            } else {
                if (bHead == nullptr) {
                    bHead = bPtr = head;
                } else {
                    bPtr->next = head;
                    bPtr = head;
                }
            }
            head = head->next;
        }
        if (aHead != nullptr && bHead != nullptr) {
            aPtr->next = bHead;
            bPtr->next = nullptr;
            return aHead;
        } else if (aHead == nullptr) {
            return bHead;
        } else {
            return aHead;
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
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        
        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;
        
        for (ListNode *cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                left_cur->next = cur;
                left_cur = cur;
            } else {
                right_cur->next = cur;
                right_cur = cur;
            }
        }
        
        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        
        return left_dummy.next;
    }
};
