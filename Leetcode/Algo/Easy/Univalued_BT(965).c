/***********************
	965. Univalued Binary Tree
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

Example 1:

Input: [1,1,1,1,1,null,1]
Output: true

Example 2:

Input: [2,2,2,5,2]
Output: false

Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
*************************/

typedef struct TreeNode t;

void helper(t* root,bool* f){
    if(!root) return;
    if(root->left){
        if(root->left->val!=root->val) {
            *f=0; return;
        }
        else{
            helper(root->left,f);
        }
    }
    if(root->right){
        if(root->right->val!=root->val) {
            *f=0; return;
        }
        else{
            helper(root->right,f);
        }
    }
    
}

bool isUnivalTree(t* root){
    bool f=1;
    helper(root,&f);
    return f;
    
}
