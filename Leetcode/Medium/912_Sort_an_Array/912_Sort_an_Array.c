/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline void swap(int *a, int *b)
{
    //if(a!=b)
    {
        (*a) ^= (*b);
        (*b) ^= (*a);
        (*a) ^= (*b);
    }
}
void heapify(int *arr, int root, int size)
{
    int idx_max = root;
    int left = (root<<1)+1;
    int right = (root<<1)+2;
    if(left<size && arr[left]>arr[idx_max])
        idx_max = left;
    if(right<size && arr[right]>arr[idx_max])
        idx_max = right;
    if(idx_max != root)
    {
        swap(arr+root, arr+idx_max);
        heapify(arr, idx_max, size);
    }
    return;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    for(int i=numsSize/2-1; i>=0; i--)
    {
        heapify(nums, i, numsSize);
    }
    for(int i=numsSize-1; i>0; i--)
    {
        swap(nums+i, nums);
        heapify(nums, 0, i);
    }
    *returnSize = numsSize;
    return nums;
}