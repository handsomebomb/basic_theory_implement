/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* postSearch(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* lnode = NULL, *rnode = NULL;
    if(root->left) {
        lnode = postSearch(root->left, p, q);
    }
    if(root->right) {
        rnode = postSearch(root->right, p, q);    
    }
    if(root == p || root == q) {     
        return root;
    }
    if(lnode && rnode )
        return root;
    else
        return lnode?lnode:rnode;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    return postSearch(root, p, q);   
}

/*#define MAX_NUM 100000
void findTree(struct TreeNode* root, struct TreeNode* target, struct TreeNode* record, int* layer, int tmp_lay, bool* flag){
    if((*flag)||(root==NULL)) return;
    record[tmp_lay++] = *root;
    printf("val:%d, layer:%d \n", root->val, *layer);
    if(root->val==target->val)
    {
        *flag = true;
        *layer = tmp_lay-1;
        return;
    }
    findTree(root->left, target, record, layer, tmp_lay, flag);
    findTree(root->right, target, record, layer, tmp_lay, flag);
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode p_rec[MAX_NUM] = {0};
    struct TreeNode q_rec[MAX_NUM] = {0};
    int p_layer = 0, q_layer = 0;
    bool find = 0;
    findTree(root, p, p_rec, &p_layer, 0, &find);
    find = 0;
    findTree(root, q, q_rec, &q_layer, 0, &find);
    printf("%d %d \n", p_layer, q_layer);
    struct TreeNode* res = NULL;
    int idx = (p_layer>q_layer?p_layer:q_layer);
    printf("%d \n", idx);
    for(int i=idx; i>=0; i++)
    {
        if((p_rec[i].val)==(q_rec[i].val))
        {
            printf("chk \n");
            res = &(p_rec[i]);
            break;
        }
    }
    
    return res;
}*/