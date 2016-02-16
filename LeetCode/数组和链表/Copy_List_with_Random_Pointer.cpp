// 太耗时了！
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return head;
        RandomListNode *newHead = new RandomListNode(head->label);
        RandomListNode *newP = newHead;
        for (RandomListNode *p = head->next; p; p = p->next) {
            RandomListNode *newNode = new RandomListNode(p->label);
            newP->next = newNode;
            newP = newP->next;
        }
        newP->next = NULL;
        
        newP = newHead;
        for (RandomListNode *p = head; p; p = p->next) {
            if (p->random == nullptr) {
                newP->random = NULL;
            } else {
                RandomListNode *target = p->random;
                for (RandomListNode *a = head, *b = newHead; a; a = a->next, b = b->next) {
                    if (a == target) {
                        newP->random = b;
                        break;
                    }
                }
            }
            newP = newP->next;
        }
        
        return newHead;
    }
};

// O(n)
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode *cur = head; cur != nullptr; ) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        for (RandomListNode *cur = head; cur != nullptr; ) {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        RandomListNode dummy(-1);
        for (RandomListNode *cur = head, *new_cur = &dummy; cur != nullptr; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
