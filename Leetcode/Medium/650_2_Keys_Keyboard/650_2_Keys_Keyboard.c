int minSteps(int n) {
    if(n<2)
        return 0;
    int res = 0;
    int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for(int i=0; i<11; i++)
    {
        while((n%prime[i]) == 0)
        {
            res += prime[i];
            n /= prime[i];
        }
    }
    if(n>1)
        return res+n;
    else
        return res;
}