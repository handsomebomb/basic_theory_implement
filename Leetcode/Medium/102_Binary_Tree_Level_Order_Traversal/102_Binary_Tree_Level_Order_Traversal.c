/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_NUM 2001

void BFS(int* returnSize, int** returnColumnSizes, int* record, int rec_str, struct TreeNode** basedPts, int ptsCnt){
    int cnt = 0;
    int max_num = 2*ptsCnt;
    struct TreeNode* tmp[max_num];
    for(int i=0; i<ptsCnt; i++)
    {
        if(basedPts[i]->left != NULL)
        {
            tmp[cnt] = basedPts[i]->left;
            record[(rec_str+cnt)] = basedPts[i]->left->val;
            cnt++;
        }
        if(basedPts[i]->right != NULL)
        {
            tmp[cnt] = basedPts[i]->right;
            record[(rec_str+cnt)] = basedPts[i]->right->val;
            cnt++;
        }
    }
    if(cnt!=0)
    {
        int tmpcnt = *returnSize;
        returnColumnSizes[0][*returnSize] = cnt;
        *returnSize = (*returnSize)+1;
        tmpcnt = *returnSize;
        BFS(returnSize, returnColumnSizes, record, rec_str+cnt, tmp, cnt);
    }
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root==NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        returnColumnSizes[0][0] = 0;
        return NULL;
    }
    int record[MAX_NUM];
    record[0] = root->val;
    *returnSize = 1;
    *returnColumnSizes = (int*)malloc(sizeof(int)*MAX_NUM);
    returnColumnSizes[0][0] = 1;
    struct TreeNode* basedPts[1];
    basedPts[0] = root;
    BFS(returnSize, returnColumnSizes, record, 1, basedPts, 1);
    int** res = (int**)malloc((*returnSize)*sizeof(int*));
    int idx = -1;
    for(int i=0; i<(*returnSize); i++)
    {
        res[i] = (int*)malloc((returnColumnSizes[0][i])*sizeof(int));
        for(int j=0; j<returnColumnSizes[0][i]; j++)
        {
            idx++;
            res[i][j] = record[idx];
        }
    }
    
    return res;
}