/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    struct ListNode *res, *curr, *next;
    curr = (struct ListNode*)malloc(sizeof(struct ListNode));
    res = curr;
    int v1, v2, tmp, carry = 0;
    res->val = 0;
    while(l1 || l2)
    {
        v1=l1?l1->val:0;
        v2=l2?l2->val:0;
        tmp = v1 + v2 + carry;
        if(tmp>9)
        {
            tmp %= 10;
            carry = 1;
        }
        else
            carry = 0;
        next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next->val = tmp;
        curr->next = next;
        curr = curr->next;
        if(l1)
            l1=l1->next;
        if(l2)
            l2=l2->next;
    }
    if(carry)
    {
        next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next->val = carry;
        curr->next = next;
    }
    next->next = NULL;
    curr = res->next;
    free(res);
    return curr;
    
}