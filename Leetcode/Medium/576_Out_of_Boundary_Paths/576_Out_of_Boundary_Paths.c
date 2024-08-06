#define MODULA (1000000007)

int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    long res[m+2][n+2][maxMove+1];
    for(int r=0; r<(m+2); r++)
    {
        for(int c=0; c<(n+2); c++)
        {
            for(int s=0; s<(maxMove+1); s++)
            {
                if(r==0 && s==0) res[r][c][s] = 1;
                else if(r==(m+1) && s==0) res[r][c][s] = 1;
                else if(c==(n+1) && s==0) res[r][c][s] = 1;
                else if(c==0 && s==0) res[r][c][s] = 1;
                else res[r][c][s] = 0;
            }
        }
    }
    for(int s=1; s<(maxMove+1); s++)
    {
        for(int r=1; r<=m; r++)
        {
            for(int c=1; c<=n; c++)
            {
                res[r][c][s] = (res[r+1][c][s-1]%MODULA)+(res[r-1][c][s-1]%MODULA)+(res[r][c+1][s-1]%MODULA)+(res[r][c-1][s-1]%MODULA);
            }
        }
    }
    int ans = 0;
    for(int s=1; s<=maxMove; s++)
    {
        ans = (ans+res[startRow+1][startColumn+1][s])%MODULA;
    }
    return ans;
}