/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void subflatten(struct TreeNode* root, struct TreeNode** tail){
    if(root==NULL) return;
    subflatten(root->right, tail);
    subflatten(root->left, tail);
    root->right = *tail;
    root->left = NULL;
    *tail = root;
}
void flatten(struct TreeNode* root){
    struct TreeNode *tail = NULL;
    subflatten(root, &tail);
}