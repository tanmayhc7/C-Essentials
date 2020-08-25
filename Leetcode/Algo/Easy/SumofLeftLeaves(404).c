/**********************
	404. Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
**********************/

typedef struct TreeNode t;

void helper(t* root,int *res){
    if(!root) return;
    if(!root->left && !root->right) return;
    if(root->left && root->left->left==NULL && root->left->right==NULL){
        (*res)+=root->left->val;
    }
    
    if(root->left) helper(root->left,res);
    if(root->right) helper(root->right,res);
}


int sumOfLeftLeaves(t* root){
 
    int res=0;
    helper(root,&res);
    return res;
}
