#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int cmpS2B(const void* p1, const void* p2){
    return *(int*)p1 - *(int*)p2;
}

int longestConsecutive(int* nums, int numsSize){
    if(numsSize<=1)
        return numsSize;
    qsort(nums, numsSize, sizeof(int), cmpS2B);
    int maxLen = 1;
    int curLen = 1;
    for(int i=1; i<numsSize; i++){
        if(nums[i] == nums[i-1]+1)
            curLen++;
        else if(nums[i] == nums[i-1])
            continue;
        else
            curLen = 1;
        maxLen = MAX(maxLen,curLen);
    }
    return maxLen;
}

/*#define MAX_NUM 100001
#define ABS_IDX(a) a>=0?a:(a+1000*MAX_NUM)

int longestConsecutive(int* nums, int numsSize){
    if(numsSize<=1)
        return numsSize;
    
    bool hash_list[MAX_NUM];
    for(int i=0; i<MAX_NUM; i++)
    {
        hash_list[i] = 0;
    }
    for(int i=0; i<numsSize; i++)
    {
        if(hash_list[(ABS_IDX(nums[i]))%MAX_NUM]!=1)
            hash_list[(ABS_IDX(nums[i]))%MAX_NUM] = 1;
    }
    int curLen = 0;
    int maxLen = 1;
    int curNum;
    for(int i=0; i<numsSize; i++)
    {
        if((hash_list[(ABS_IDX(nums[i]-1))%MAX_NUM]!=1) || (nums[i]==(-1000000000)))
        {
            curNum = nums[i];
            curLen = 1;
            while((hash_list[(ABS_IDX(curNum+1))%MAX_NUM]) && (curNum!=1000000000))
            {
                curNum++;
                curLen++;
            }
            maxLen = MAX(maxLen,curLen);
        }
    }
    return MAX(maxLen,curLen);
}*/