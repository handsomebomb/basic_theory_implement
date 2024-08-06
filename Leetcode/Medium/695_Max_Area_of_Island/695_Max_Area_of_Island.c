#define MAX(a,b) a>b?a:b
bool** done;
int maxRow;
int maxCol;

int subArea(int** grid, int row, int col)
{
    if(row<0 || row>=maxRow || col<0 || col>=maxCol || done[row][col] || grid[row][col]==0)
        return 0;
    done[row][col] = true;
    return 1+subArea(grid, row+1, col)+subArea(grid, row, col+1)+subArea(grid, row-1, col)+subArea(grid, row, col-1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    done = (bool**)malloc(gridSize*sizeof(bool*));
    maxRow = gridSize;
    maxCol = *gridColSize;
    for(int i=0; i<gridSize; i++)
    {
        *(done+i) = (bool*)calloc((*gridColSize), sizeof(bool));
    }
    int res = 0;
    for(int row=0; row<gridSize; row++)
    {
        for(int col=0; col<(*gridColSize); col++)
        {
            if(done[row][col] || grid[row][col]==0) continue;
            int tmp = subArea(grid, row, col);
            res = MAX(res,tmp);
        }
    }
    for(int i=gridSize-1; i>=0; i--)
    {
        free(*(done+i));
    }
    free(done);
    return res;
}