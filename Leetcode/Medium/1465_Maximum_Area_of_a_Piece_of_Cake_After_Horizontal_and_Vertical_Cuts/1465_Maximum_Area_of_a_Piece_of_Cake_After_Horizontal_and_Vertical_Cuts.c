#define max(a,b) a>b?a:b

long long modMultiple(long long m1, long long m2, long long mod)
{
    /// m1 * m2 % mod
    long long ret = 0;
    m2 %= mod;
    while(m1)
    {
        if(m1&1)
            ret = (ret+m2)%mod;
        m1 >>= 1;
        m2 = (m2<<1)%mod;
    }
    return ret;
}

int partition(int* nums, int left, int right)
{
    int i =left;
    for(int j=left; j<right; j++)
    {
        if(nums[j]<nums[right])
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

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
    QuickSort(horizontalCuts, 0, horizontalCutsSize-1);
    QuickSort(verticalCuts, 0, verticalCutsSize-1);
    int maxH = horizontalCuts[0], maxW = verticalCuts[0];
    int i, j;
    for(i=1; i<horizontalCutsSize; i++)
    {
        maxH = max((horizontalCuts[i]-horizontalCuts[i-1]),maxH);
    }
    maxH = max((h-horizontalCuts[i-1]),maxH);
    for(j=1; j<verticalCutsSize; j++)
    {
        maxW = max((verticalCuts[j]-verticalCuts[j-1]),maxW);
    }
    maxW = max((w-verticalCuts[j-1]),maxW);
    
    return modMultiple(maxH, maxW, 1e9+7);
}