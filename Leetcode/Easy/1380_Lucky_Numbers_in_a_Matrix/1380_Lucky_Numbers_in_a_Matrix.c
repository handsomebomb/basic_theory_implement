/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX_LEN 50
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *res = (int *)malloc(sizeof(int)*MAX_LEN);
    *returnSize = 0;
    for(int row=0; row<matrixSize; row++)
    {
        int idx_min = 0;
        int idx_max;
        for(int col=1; col<*matrixColSize; col++)
        {
            if(matrix[row][col]<matrix[row][idx_min])
                idx_min = col;
        }
        for(idx_max=0; idx_max<matrixSize; idx_max++)
        {
            if(idx_max==row)
                continue;
            if(matrix[row][idx_min]<matrix[idx_max][idx_min])
                break;
        }
        if(idx_max==matrixSize)
        {
            res[(*returnSize)++] = matrix[row][idx_min];
        }
    }
    return res;
}