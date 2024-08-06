typedef struct {
    int cnt;
    int* elem;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* res = (NumArray*)malloc(sizeof(NumArray));
    /*res->elem = (int*)malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++){
        (res->elem)[i] = nums[i];
    }*/
    res->elem = nums;
    res->cnt = numsSize;
    return res;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    (obj->elem)[index] = val;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    for(int i=left; i<=right; i++){
        sum += (obj->elem)[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    //free(obj->elem);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/