/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

void deleteNode(struct ListNode* node) {
    ListNode *p = node;
    p->val = p->next->val;
    p->next = p->next->next;
}