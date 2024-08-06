int partition(int* nums, int left, int right)
{
    int i =left;
    for(int j=left; j<right; j++)
    {
        if(nums[j]>nums[right])
        {
            if(i!=j)
            {
                nums[i] ^= nums[j];
                nums[j] ^= nums[i];
                nums[i] ^= nums[j];
            }
            i++;
        }
    }
    if(i!=right)
    {
        nums[i] ^= nums[right];
        nums[right] ^= nums[i];
        nums[i] ^= nums[right];
    }
    return i;
}

void QuickSort(int* nums, int left, int right)
{
    if(left<right)
    {
        int standard = partition(nums, left, right);
        QuickSort(nums, left, standard-1);
        QuickSort(nums, standard+1, right);
    }
}

int minMoves2(int* nums, int numsSize){
    int mid;
    int cnt = 0;
    QuickSort(nums, 0, numsSize-1);
    if(numsSize&1)
        mid = nums[numsSize/2];
    else
        mid = (nums[numsSize/2]+nums[(numsSize/2)-1])/2;
    
    for(int i=0; i<numsSize; i++)
    {
        if(mid<nums[i])
            cnt += (nums[i]-mid);
        else
            cnt += (mid-nums[i]);
    }
    return cnt;
}