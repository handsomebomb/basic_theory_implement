int majorityElement(int* nums, int numsSize){
    int cnt = 1;
    int res = nums[0];
    for(int i=1; i<numsSize;i++){
        if(res==nums[i]) cnt++;
        else if(cnt>0) cnt--;
        else {
            res = nums[i];
            cnt++;
        }
    }
    return res;
}