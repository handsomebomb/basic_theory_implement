/// for loop ///
int fib(int n){
    if(n<=1)
        return n;
    int n1 = 0, n2 = 1, res;
    for(int i = 2; i<=n; i++)
    {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
    return res;
}
/// Recursive ///
/*
int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}
*/