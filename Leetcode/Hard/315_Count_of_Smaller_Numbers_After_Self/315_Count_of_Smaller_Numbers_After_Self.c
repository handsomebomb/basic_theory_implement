/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int cntRec[20001] = {0};
typedef union _node_t{
    long long all;
    struct{
        int val;
        int idx;
    }bit;
}node_t;

void merge(node_t *arr, int low, int mid, int high, int *cntRec) {
    int leftIndex = low;
    int rightIndex = mid + 1;
    int tempArrLength = high - low + 1;
    node_t tempArr[tempArrLength];
    int tempIndex = 0;

    while (leftIndex <= mid && rightIndex <= high) {
        if (arr[leftIndex].bit.val <= arr[rightIndex].bit.val) {
            tempArr[tempIndex].all = arr[leftIndex].all;
            cntRec[arr[leftIndex].bit.idx] = cntRec[arr[leftIndex].bit.idx]+rightIndex-mid-1;
            leftIndex++;
        }
        else {
            tempArr[tempIndex].all = arr[rightIndex].all;
            //cntRec[arr[rightIndex]+10000] = cntRec[arr[rightIndex]+10000]+mid+1-leftIndex;
            rightIndex++;
        }
        tempIndex++;
    }
    if (leftIndex > mid) {
        while (rightIndex <= high) {
            tempArr[tempIndex].all = arr[rightIndex].all;
            rightIndex++;
            tempIndex++;
        }
    }
    else {
        while (leftIndex <= mid) {
            tempArr[tempIndex].all = arr[leftIndex].all;
            cntRec[arr[leftIndex].bit.idx] = cntRec[arr[leftIndex].bit.idx]+rightIndex-mid-1;
            leftIndex++;
            tempIndex++;
        }
    }
    leftIndex = low;
    for (tempIndex=0; tempIndex<tempArrLength; tempIndex++) {
        arr[leftIndex].all = tempArr[tempIndex].all;
        leftIndex++;
    }
}
void mergeSort(int *arr, int low, int high, int *cntRec) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid, cntRec);
        mergeSort(arr, mid + 1, high, cntRec);
        merge(arr, low, mid, high, cntRec);
    }
}
int* countSmaller(int* nums, int numsSize, int* returnSize){
    int* cntRec = (int*)calloc(numsSize, sizeof(int));
    //memset(cntRec, 0, numsSize*sizeof(int));
    *returnSize = numsSize;
    if(numsSize==2)
    {
        if(nums[0]>nums[1]) cntRec[0] = 1;
        return cntRec;
    }
    if(numsSize==1) return cntRec;
    
    //int backup[numsSize];
    node_t* backup = (node_t*)calloc(numsSize, sizeof(node_t));
    for(int i=0; i<numsSize; i++)
    {
        backup[i].bit.val = nums[i];
        backup[i].bit.idx = i;
    }
    mergeSort(backup, 0, numsSize-1, cntRec);
    
    /*for(int i=0; i<numsSize; i++)
    {
        //printf("%d \n", cntRec[backup[i]+10000]);
        res[i] = cntRec[backup[i]+10000];
    }*/
    return cntRec;
}