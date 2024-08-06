int minSwaps(int* nums, int numsSize) {
    int count_one = 0, cur_count = 0, max_count = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == 1)
            count_one++;
    }
    if(count_one%numsSize == 0)
        return 0;

    for(int i=0; i<count_one; i++)
    {
        if(nums[i] == 1)
            cur_count++;
    }
    max_count = cur_count;

    for(int i=1; i<numsSize; i++)
    {
        if(nums[i-1] == 1)
            cur_count--;
        if(nums[(i-1+count_one)%numsSize] == 1)
            cur_count++;
        max_count = (cur_count>max_count)?cur_count:max_count;
    }
    return (count_one-max_count);
}