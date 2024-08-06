/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left==right) return head;
    struct ListNode* arr[right-left+1];
    struct ListNode* cur = head;
    int idx = 1;
    while(cur!=NULL && idx<=right)
    {
        if(idx>=left && idx<=right)
        {
            arr[right-idx] = cur;
        }
        cur = cur->next;
        idx++;
    }
    struct ListNode* res;
    if(left==1)
    {
        res = arr[0];
        cur = res;
        struct ListNode* tmp = arr[0]->next;
        for(int i=1; i<(right-left+1); i++)
        {
            cur->next = arr[i];
            printf(" %d \n", cur->val);
            cur = cur->next;
        }
        cur->next = tmp;
    }
    else
    {
        res = head;
        cur = res;
        for(int i=1; i<(left-1); i++)
        {
            printf("%d \n", cur->val);
            cur = cur->next;
        }
        struct ListNode* tmp = arr[0]->next;
        for(int i=0; i<(right-left+1); i++)
        {
            cur->next = arr[i];
            printf(" %d \n", cur->val);
            cur = cur->next;
        }
        cur->next = tmp;
    }
    
    
    return res;
}