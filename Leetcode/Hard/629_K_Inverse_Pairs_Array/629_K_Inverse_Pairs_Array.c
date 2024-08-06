#define MODULO (1000000007)

int kInversePairs(int n, int k){
    if(n==1 && k==0) return 1;
    if(n==1 && k==1) return 0;
    long res[n+1][k+1];
    for(int i=0; i<(n+1); i++)
    {
        for(int j=0; j<(k+1); j++)
        {
            res[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        res[i][0] = 1;
    }
    for(int i=2; i<=n; i++)
    {
        int cmbs = (i-1)*i/2;
        for(int j=1; j<=k && j<=cmbs; j++)
        {
    		res[i][j] = (res[i][j-1]%MODULO) + ((MODULO+res[i-1][j]-(j>=i?res[i-1][j-i]:0))%MODULO);
			res[i][j] %= MODULO;
        }
    }
    return res[n][k];
}

/*int kInversePairs(int n, int k){
    if(n==1 && k==0) return 1;
    if(n==1 && k==1) return 0;
    long* res1 = (long*)calloc(1,sizeof(long));
    res1[0] = 1;
    int kinds_old = 1;
    for(int i=2; i<=n; i++)
    {
        int kinds = 1;
        for(int add = 1; add<i; add++)
        {
            kinds += add;
        }
        //printf("%d \n", kinds);
        long* res2 = (long*)calloc(kinds,sizeof(long));
        for(int kind=0; kind<kinds; kind++)
        {
            if(kind>k) break;
            for(int j=0; j<i; j++)
            {
                if((kind-j)>=0 && (kind-j)<kinds_old) res2[kind]=((res1[kind-j]%MODULO)+(res2[kind]%MODULO)%MODULO);
            }
        }
        long* tmpPtr = res1;
        res1 = res2;
        free(tmpPtr);
        kinds_old = kinds;
    }
    //printf("%d %d %d %d %d %d %d %d \n", kinds_old, res1[0], res1[1], res1[2], res1[3], res1[4], res1[5], res1[6]);
    if(k>=kinds_old)
        return 0;
    else
    {
        int ans = res1[k];
        free(res1);
        return ans;
    }
}*/