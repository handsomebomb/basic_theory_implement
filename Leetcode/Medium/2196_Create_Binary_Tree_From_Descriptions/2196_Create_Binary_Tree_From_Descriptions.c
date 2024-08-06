/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode *tmp[100000] = {0};
    struct TreeNode *root= (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = descriptions[0][0];
    root->left = root->right = NULL;
    tmp[root->val-1] = root;
    //printf("root 0x%x \n", (unsigned long long)root);

    for(int i=0; i<descriptionsSize; i++)
    {
        //printf("loop %d \n", i);
        if(tmp[(descriptions[i][0]-1)] != NULL)
        {
            struct TreeNode *parent = tmp[(descriptions[i][0]-1)];
            struct TreeNode *child;
            if(tmp[(descriptions[i][1]-1)] != NULL)
            {
                child = tmp[(descriptions[i][1]-1)];
                root = (((unsigned long long)root)^((unsigned long long)child));
            }
            else
            {
                child = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                child->val = descriptions[i][1];
                child->left = child->right = NULL;
                tmp[(descriptions[i][1]-1)] = child;
            }

            if(descriptions[i][2] == 1)
                parent->left = child;
            else
                parent->right = child;
                
        }
        else if(tmp[(descriptions[i][1]-1)] != NULL)
        {
            struct TreeNode *parent= (struct TreeNode *)malloc(sizeof(struct TreeNode));
            struct TreeNode *child = tmp[(descriptions[i][1]-1)];
            parent->val = descriptions[i][0];
            parent->left = parent->right = NULL;
            tmp[(descriptions[i][0]-1)] = parent;

            if(descriptions[i][2] == 1)
                parent->left = child;
            else
                parent->right = child;
            //root = parent;
            root = (((unsigned long long)root)^((unsigned long long)parent));
            root = (((unsigned long long)root)^((unsigned long long)child));
        }
        else
        {
            struct TreeNode *parent= (struct TreeNode *)malloc(sizeof(struct TreeNode));
            struct TreeNode *child= (struct TreeNode *)malloc(sizeof(struct TreeNode));
            parent->val = descriptions[i][0];
            child->val = descriptions[i][1];
            parent->left = parent->right = NULL;
            child->left = child->right = NULL;
            tmp[(descriptions[i][0]-1)] = parent;
            tmp[(descriptions[i][1]-1)] = child;
            if(descriptions[i][2] == 1)
                parent->left = child;
            else
                parent->right = child;

            root = (((unsigned long long)root)^((unsigned long long)parent));
        }
    }

    return root;
}