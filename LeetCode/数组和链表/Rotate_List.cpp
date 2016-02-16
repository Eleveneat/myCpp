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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        size_t len = 0;
        ListNode *tail = head;
        for (ListNode *ptr = head; ptr; ptr = ptr->next) {
            len++;
            tail = ptr;
        }
        k %= len;
        tail->next = head;
        int count = len - k;
        while (count--)
            tail = tail->next;
        head = tail->next;
        tail->next = nullptr;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        size_t len = 1;
        ListNode *tail = head;
        while (tail->next) {
            len++;
            tail = tail->next;
        }
        k = len - k % len;
        tail->next = head;
        for (size_t i = 0; i < k; i++)
            tail = tail->next;
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
