/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if(head==NULL || head->next==NULL) return head;
    
    struct ListNode *less = NULL;
    struct ListNode *gter = NULL;
    struct ListNode *cur_less = NULL;
    struct ListNode *cur_gter = NULL;
    struct ListNode *cur = head;
    while(cur)
    {
        if(cur->val<x)
        {
            if(less)
            {
                cur_less->next = cur;
                cur_less = cur_less->next;
            }
            else
            {
                less = cur;
                cur_less = cur;
            }
        }
        else
        {
            if(gter)
            {
                cur_gter->next = cur;
                cur_gter = cur_gter->next;
            }
            else
            {
                gter = cur;
                cur_gter = cur;
            }
        }
        cur = cur->next;
    }
    if(less==NULL || gter==NULL) return head;
    cur_gter->next = NULL;
    cur_less->next = gter;
    return less;
}