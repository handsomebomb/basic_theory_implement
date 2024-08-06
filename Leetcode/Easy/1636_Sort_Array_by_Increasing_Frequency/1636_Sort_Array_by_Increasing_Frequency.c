/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int freq[201] = {0};
int freq_cmp(const void *a, const void *b)
{
    int *val_1 = (int *)a;
    int *val_2 = (int *)b;
    int equal = 0;
    if((freq[*val_1+100]==freq[*val_2+100]) && (*val_2 > *val_1))
        equal = 1;
    return (freq[*val_1+100]-freq[*val_2+100]+equal);
}
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int vals[numsSize];
    int wptr = 0;
    for(int i=0; i<numsSize; i++)
    {  
        if(freq[nums[i]+100]==0)
            vals[wptr++] = nums[i];
        freq[nums[i]+100]++;
    }
    qsort(vals, wptr, sizeof(int), freq_cmp);

    int *res = (int *)malloc(sizeof(int)*numsSize);
    for(int i=0, j=0; i<numsSize;)
    {
        while(freq[vals[j]+100]>0)
        {
            res[i++] = vals[j];
            freq[vals[j]+100]--;
        }
        j++;
    }
    *returnSize = numsSize;
    return res;
}