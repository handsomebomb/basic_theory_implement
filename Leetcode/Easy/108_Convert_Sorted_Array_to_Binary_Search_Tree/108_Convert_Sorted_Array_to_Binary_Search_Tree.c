/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* writein(int* nums, int str, int end){
    if (str<=end) {
        int mid = (end+str)/2;
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = nums[mid];
        node->left = writein(nums, str, mid-1);
        node->right = writein(nums, mid+1, end);
        return node;
    }
    else return NULL;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return writein(nums, 0, numsSize-1);
}
