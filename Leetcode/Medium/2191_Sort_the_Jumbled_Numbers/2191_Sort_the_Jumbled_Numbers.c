/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int value;
    int mapped;
}element;

int cmp_mapped (const void * a, const void * b)
{
    element *ptrA = (element *)a;
    element *ptrB = (element *)b;
    return ( ptrA->mapped - ptrB->mapped);
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    element arr[numsSize];
    int *res = (int *)malloc(sizeof(int)*numsSize);
    for(int i=0; i<numsSize; i++)
    {
        bool begin = false;
        arr[i].value = arr[i].mapped = nums[i];
        for(int mod=100000000; mod>0; mod/=10)
        {
            int single_num = (arr[i].mapped/mod)%10;
            if(begin==false && single_num==0 && arr[i].mapped!=0)
                continue;
            begin = true;
            arr[i].mapped -= (single_num*mod);
            arr[i].mapped += (mapping[single_num]*mod);
        }
    }
    *returnSize = numsSize;
    qsort(arr, numsSize, sizeof(element), cmp_mapped);

    for(int i=0; i<numsSize; i++)
        res[i] = arr[i].value;
    return res;
}