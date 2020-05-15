/*
 * Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int L, int R){
     if(!root)    return 0;
    int result=0;
    if(root->val<L)
    {
        result+=rangeSumBST(root->right,L,R);
    }
    else if(root->val>R)
    {
        result+=rangeSumBST(root->left,L,R);
    }
    else
    {
        result+=root->val;
        result+=rangeSumBST(root->left,L,R);
        result+=rangeSumBST(root->right,L,R);
    }
    return result;

}

