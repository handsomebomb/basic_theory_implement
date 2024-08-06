/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int **matrix = (int **)calloc(rowSumSize, sizeof(int *));
    *returnSize = rowSumSize;
    *returnColumnSizes = (int *)malloc(rowSumSize*sizeof(int));
    for(int row=0; row<rowSumSize; row++)
        matrix[row] = (int *)calloc(colSumSize, sizeof(int));
    for(int row=0, col=0; (row<rowSumSize) && (col<colSumSize);)
    {
        /*if(rowSum[row]<colSum[col])
            matrix[row][col] = rowSum[row];
        else
            matrix[row][col] = colSum[col];*/
        matrix[row][col] = (rowSum[row]<colSum[col])?rowSum[row]:colSum[col];
        rowSum[row] -= matrix[row][col];
        colSum[col] -= matrix[row][col];
        if(rowSum[row])
            col++;
        else
        {
            returnColumnSizes[0][row++] = colSumSize;
            //row++;
        }
    }
    return matrix;
}