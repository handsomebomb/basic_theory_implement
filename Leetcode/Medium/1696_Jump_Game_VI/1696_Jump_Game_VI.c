#define MAX(a,b) a>b?a:b

typedef struct pri_q {
    int val;
    int idx;
    struct pri_q* next;
}pri_q;

pri_q* push(pri_q* que, pri_q* elem)
{
    if(que == NULL)
    {
        free(que);
        return elem;
    }
    pri_q* pre_ptr = que;
    pri_q* cur_ptr = pre_ptr->next;
    if(elem->val==pre_ptr->val)
    {
        pre_ptr->idx = MAX(elem->idx, pre_ptr->idx);
        free(elem);
        return que;
    }
    else if(elem->val>pre_ptr->val)
    {
        elem->next = pre_ptr;
        return elem;
    }
    while(cur_ptr!=NULL)
    {
        if(elem->val==cur_ptr->val)
        {
            cur_ptr->idx = MAX(elem->idx, cur_ptr->idx);
            free(elem);
            return que;
        }
        else if(elem->val>cur_ptr->val)
        {
            elem->next = cur_ptr;
            pre_ptr->next = elem;
            return que;
        }
        pre_ptr = cur_ptr;
        cur_ptr = cur_ptr->next;
    }
    pre_ptr->next = elem;
    return que;
}

pri_q* pop(pri_q* que)
{
    pri_q* elem = que;
    que = que->next;
    elem->next = NULL;
    free(elem);
    return que;
}

int maxResult(int* nums, int numsSize, int k){
    if(numsSize<=0)
        return 0;
    else if(numsSize==1)
        return nums[numsSize-1];
    
    pri_q* que = (pri_q*)malloc(sizeof(pri_q));
    que->val = nums[0];
    que->idx = 0;
    que->next = NULL;
    int res = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        while((i-(que->idx)) > k)
        {
            que = pop(que);
        }
        res = que->val + nums[i];
        //printf("%d %d %d\n",que->val, nums[i], res);
        pri_q* elem = (pri_q*)malloc(sizeof(pri_q));
        elem->val = res;
        elem->idx = i;
        elem->next = NULL;
        que = push(que, elem);
    }
    return res;
}