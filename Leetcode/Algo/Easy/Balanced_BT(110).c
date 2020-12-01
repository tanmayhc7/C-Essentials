/*************************************************
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
**************************************************/

int get_ht(struct TreeNode* root){
    if(!root) return 0;
    
    int left=get_ht(root->left);
    int right=get_ht(root->right);
        
    return 1 + (left > right ? left : right);
    
}

bool isBalanced(struct TreeNode* root){
    if(!root || (!root->left && !root->right)) return 1;
    
    int ht_left=get_ht(root->left);
    int ht_right=get_ht(root->right);
    
    if(abs(ht_left-ht_right)>1) return 0;
    
    return isBalanced(root->left) && isBalanced(root->right);
    
}
