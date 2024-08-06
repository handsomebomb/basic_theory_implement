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
#define MAX_NUM 101
#define MAX(a,b) a>b?a:b
void tree2arr(struct TreeNode* root, int* array, int* layer, int idx)
{
    if(root==NULL) return;
    array[idx++] = root->val;
    *layer = (MAX(idx,*layer));
    tree2arr(root->left, array, layer, idx);
    tree2arr(root->right, array, layer, idx);
}
int* rightSideView(struct TreeNode* root, int* returnSize){
    int* nodes = (int*)malloc(sizeof(int)*MAX_NUM);
    int* layer = (int*)malloc(sizeof(int));
    *layer = 0;
    
    tree2arr(root, nodes, layer, 0);
    *returnSize = *layer;
    free(layer);
    return nodes;
}