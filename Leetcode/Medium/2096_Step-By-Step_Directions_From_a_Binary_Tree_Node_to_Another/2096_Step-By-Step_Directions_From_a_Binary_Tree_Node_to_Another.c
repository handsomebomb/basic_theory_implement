/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define DEPTH 100000
bool find_path(struct TreeNode* root, int tar, char *s, int *idx)
{
    if(root->val == tar)
        return true;
    if((root->left != NULL) && find_path(root->left, tar, s, idx))
        s[(*idx)++] = 'L';
    else if((root->right != NULL) && find_path(root->right, tar, s, idx))
        s[(*idx)++] = 'R';

    return (*idx > 0);
}
char* getDirections(struct TreeNode* root, int startValue, int destValue) {
    char sPath[DEPTH], dPath[DEPTH];
    int sLen = 0, dLen = 0;
    
    find_path(root, startValue, sPath, &sLen);
    find_path(root, destValue, dPath, &dLen);

    while((sLen > 0) && (dLen > 0) && (sPath[sLen-1] == dPath[dLen-1])) {
        sLen--; 
        dLen--;
    }

    char *res = malloc(sizeof(char)*(sLen+dLen+1));
    int resIdx = 0;

    for(int i = 0; i < sLen; i++)
        res[resIdx++] = 'U';

    for(int i = dLen - 1; i >= 0; i--)
        res[resIdx++] = dPath[i];

    res[resIdx] = '\0';

    return res;
}