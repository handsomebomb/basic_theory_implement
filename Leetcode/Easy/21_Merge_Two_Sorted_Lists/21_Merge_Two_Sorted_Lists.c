/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    struct ListNode *des, *tmp;
    if (l1->val < l2->val) {
        tmp = l1;
        l1 = l1->next;
    }
    else {
        tmp = l2;
        l2 = l2->next;
    }
    des = tmp;
    while (l1!=NULL && l2!=NULL) {
        if (l1->val < l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        }
        else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if (l1!=NULL) tmp->next = l1;
    if (l2!=NULL) tmp->next = l2;
    return des;
}