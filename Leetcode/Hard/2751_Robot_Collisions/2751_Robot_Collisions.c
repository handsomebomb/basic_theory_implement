/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct stack_packet stack_packet;
struct stack_packet{
    int pos;
    int hlt;
    char dir;
    int idx;
};

int cmp_by_pos (const void * a, const void * b)
{
    stack_packet *a_ptr = (stack_packet *)a;
    stack_packet *b_ptr = (stack_packet *)b;
    return ( a_ptr->pos - b_ptr->pos);
}

int cmp_by_idx (const void * a, const void * b)
{
    stack_packet *a_ptr = (stack_packet *)a;
    stack_packet *b_ptr = (stack_packet *)b;
    return ( a_ptr->idx - b_ptr->idx);
}

int last_non_zero_idx(stack_packet *array, int now_idx)
{
    int i;
    for(i=now_idx; i>0;)
    {
        if(array[--i].hlt != 0)
            return i;
    }
    if(array[i].hlt != 0)
        return i;
    else
        return now_idx;
}
int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char * directions, int* returnSize){
    int *rslt = NULL;
    if(positionsSize == 1)
    {
        rslt = (int *)malloc(sizeof(int));
        *returnSize = 1;
        *rslt = *healths;
        return rslt;
    }

    stack_packet *arr_sorted = (stack_packet *)malloc(sizeof(stack_packet)*positionsSize);
    for(int i=0; i<positionsSize; i++)
    {
        arr_sorted[i].pos = positions[i];
        arr_sorted[i].hlt = healths[i];
        arr_sorted[i].dir = directions[i];
        arr_sorted[i].idx = i;
    }
    qsort(arr_sorted, positionsSize, sizeof(stack_packet), cmp_by_pos);

    *returnSize = positionsSize;
    int idx_prev = 0, idx_post = 1;
    while(idx_post < positionsSize)
    {
        //printf(" Chk= %d %d\n", idx_prev, idx_post);
        if((arr_sorted[idx_prev].dir == 'R') && (arr_sorted[idx_post].dir == 'L'))
        {
            //printf(" ============ %d %d \n", arr_sorted[idx_prev].hlt, arr_sorted[idx_post].hlt);
            if(arr_sorted[idx_prev].hlt > arr_sorted[idx_post].hlt)
            {
                *returnSize = (*returnSize) - 1;
                arr_sorted[idx_prev].hlt--;
                arr_sorted[idx_post].hlt = 0;
                idx_post++;
                //printf(" Chk== %d %d\n", idx_prev, idx_post);
            }
            else if(arr_sorted[idx_prev].hlt < arr_sorted[idx_post].hlt)
            {
                *returnSize = (*returnSize) - 1;
                arr_sorted[idx_prev].hlt = 0;
                arr_sorted[idx_post].hlt--;
                //printf(" HLT_PRV %d %d \n", arr_sorted[idx_prev].hlt, arr_sorted[idx_post].hlt);
                int tmp = last_non_zero_idx(arr_sorted, idx_prev);
                //printf("%d %d \n", tmp, idx_prev);
                //printf(" HLT %d %d \n", arr_sorted[idx_prev].hlt, arr_sorted[idx_post].hlt);
                if(idx_prev == tmp)
                {
                    idx_prev = idx_post;
                    idx_post++;
                }
                else
                    idx_prev = tmp;
            }
            else
            {
                *returnSize = (*returnSize) - 2;
                arr_sorted[idx_prev].hlt = 0;
                arr_sorted[idx_post].hlt = 0;

                int tmp = last_non_zero_idx(arr_sorted, idx_prev);
                //printf(" == %d %d %d\n", tmp, idx_prev, idx_post);
                if(idx_prev == tmp)
                {
                    idx_prev = idx_post + 1;
                    idx_post = idx_prev + 1;
                }
                else
                {
                    idx_prev = tmp;
                    idx_post++;
                    //printf(" == %d %d %d\n", tmp, idx_prev, idx_post);
                }
            }
        }
        else
        {
            idx_prev = idx_post;
            idx_post++;
        }
    }

    if(*returnSize == 0)
        goto empty;

    qsort(arr_sorted, positionsSize, sizeof(stack_packet), cmp_by_idx);

    rslt = (int *)malloc(sizeof(int)*(*returnSize));
    int push = 0;
    for(int j=0; push<(*returnSize); j++)
    {
        if(arr_sorted[j].hlt > 0)
            rslt[push++] = arr_sorted[j].hlt;
    }

empty:
    free(arr_sorted);
    return rslt;
}