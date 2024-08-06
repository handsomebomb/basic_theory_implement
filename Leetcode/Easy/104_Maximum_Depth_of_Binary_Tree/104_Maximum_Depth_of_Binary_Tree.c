/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

int maxDepth(TreeNode* root){
    if (root == NULL) return 0;
    return 1+fmax(maxDepth(root->left),maxDepth(root->right));

}