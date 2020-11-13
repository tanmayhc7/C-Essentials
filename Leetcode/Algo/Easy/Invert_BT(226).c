/******************************************
226. Invert Binary Tree

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     8
 / \   / \
1   3 6   9
Output:

     4
   /   \
  8     2
 / \   / \
9   6 3   1
******************************************/

typedef struct TreeNode tree;

tree* invertTree(tree* root){
    if(!root) return;
    
    tree* right=root->right;
    tree* left=root->left;
    
    root->left=right;
    root->right=left;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;    
}
