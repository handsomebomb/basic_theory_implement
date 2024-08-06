void moveZeroes(int* nums, int numsSize){
    for (int i=0, last=0; i<numsSize; i++) {
        if (nums[i]!=0) {
            if (last!=i) {
                nums[i]^=nums[last];
                nums[last]^=nums[i];
                nums[i]^=nums[last];
            }
            last++;
        }
    }
}