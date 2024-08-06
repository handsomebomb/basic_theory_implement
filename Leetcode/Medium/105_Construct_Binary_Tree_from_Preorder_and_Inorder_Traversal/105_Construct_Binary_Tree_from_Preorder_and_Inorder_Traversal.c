/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize!=inorderSize) return NULL;
    if(preorderSize==0) return NULL;
    if(preorderSize==1)
    {
        struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        res->val = preorder[0];
        res->left = NULL;
        res->right = NULL;
        return res;
    }
    
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    int i;
    for(i=0; i<inorderSize; i++)
    {
        if(node->val==inorder[i]) break;
    }
    node->left = buildTree(preorder+1, i, inorder, i);
    node->right = buildTree((preorder+1+i), (preorderSize-i-1), (inorder+i+1), (inorderSize-i-1));
    
    return node;
}