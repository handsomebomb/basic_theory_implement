#define max(a,b) a>b?a:b

int candy(int* ratings, int ratingsSize){
    int sum = 0;
    int ans[ratingsSize];
    for(int i=0;i<ratingsSize;i++)
    {
        ans[i] = 1;
    }
    for(int j=1;j<ratingsSize;j++)
    {
        if (ratings[j]>ratings[j-1])
        {
            ans[j] = ans[j-1] + 1;
        }
    }
    for(int k=ratingsSize-2;k>=0;k--)
    {
        if (ratings[k]>ratings[k+1])
        {
            ans[k] = max(ans[k],(ans[k+1]+1));
        }
    }
    for(int l=0;l<ratingsSize;l++)
    {
        sum += ans[l];
    }
    return sum; 
}