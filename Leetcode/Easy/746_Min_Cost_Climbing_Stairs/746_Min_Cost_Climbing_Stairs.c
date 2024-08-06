#define MIN(a,b) a<b?a:b

int minCostClimbingStairs(int* cost, int costSize){
    int val[2] = {0}, tmp;
    for (int i = 0; i<costSize; i++)
    {
        val[i%2] = (MIN(val[0],val[1]))+cost[i];
    }
    return MIN(val[0],val[1]);
}