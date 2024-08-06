/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));
    for (int i=0; i<numRows; i++)
    {
        *(res+i) = (int*)malloc((i+1)*sizeof(int));
        *((*returnColumnSizes)+i) = i+1;
        **(res+i) = 1;
        *(*(res+i)+i) = 1;
        for (int j = 1; j < i; ++j)
        {
            *(*(res+i)+j) = *(*(res+i-1)+j) + *(*(res+i-1)+j-1);
        }
    }
    return res;
}