void sort(int *nums,int numsSize)
{
    int i,j,tmp;
    for(i=1;i<numsSize;i++)
    {
        j = i-1;
        tmp = nums[i];
        while( j>-1 && tmp<nums[j])
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=tmp;
    }
}
 
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize<2)
        return false;
    sort(nums,numsSize);
    int i;
    for(i=0;i<numsSize-1;i++)
        if(nums[i]==nums[i+1])
            return true;
    return false;
}