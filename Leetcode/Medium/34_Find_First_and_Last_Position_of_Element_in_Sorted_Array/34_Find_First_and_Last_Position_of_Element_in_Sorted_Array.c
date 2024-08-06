/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void binarySearch(int* nums, int left, int right, int target, int* range){
    if(left>right) return;
    int mid = (left+right)/2;
    if(nums[mid]==target)
    {
        if(range[0]==-1) range[0] = mid;
        if(range[1]==-1) range[1] = mid;
        if(mid<range[0]) range[0] = mid;
        if(mid>range[1]) range[1] = mid;
        binarySearch(nums, left, mid-1, target, range);
        binarySearch(nums, mid+1, right, target, range);
    }
    else if(nums[mid]>target)
    {
        binarySearch(nums, left, mid-1, target, range);
    }
    else if(nums[mid]<target)
    {
        binarySearch(nums, mid+1, right, target, range);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int)*2);
    res[0] = res[1] = -1;
    if(numsSize) binarySearch(nums, 0, numsSize-1, target, res);
    return res;
}