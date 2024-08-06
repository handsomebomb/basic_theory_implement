/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* new_pt = NULL;
    struct ListNode* nextAdd;
    while(head!=NULL){
        nextAdd = head->next;
        head->next = new_pt;
        new_pt = head;
        head = nextAdd;
    }
    return new_pt;
}