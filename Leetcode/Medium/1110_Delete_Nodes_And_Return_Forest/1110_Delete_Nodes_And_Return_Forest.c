/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode* DFS_forest_push(struct TreeNode **res, int* returnSize, struct TreeNode *root, bool *map, bool deleted)
{
    if(root == NULL)
        return root;

    root->left  = DFS_forest_push(res, returnSize, root->left, map, map[root->val]);
    root->right = DFS_forest_push(res, returnSize, root->right, map, map[root->val]);

    if(map[root->val]==0)
    {
        if(deleted)
            res[(*returnSize)++] = root;
        return root;
    }
    else
        return NULL;
    
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    bool map[1001] = {0};
    struct TreeNode **forest = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*((to_deleteSize<<1) + 1));
    *returnSize = 0;

    for(int i=0; i<to_deleteSize; i++)
    {
        map[to_delete[i]] = 1;
    }
    DFS_forest_push(forest, returnSize, root, map, true);

    return forest;
}