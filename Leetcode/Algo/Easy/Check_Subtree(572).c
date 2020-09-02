/**************************
572. Subtree of Another Tree

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
******************************/

typedef struct TreeNode tree;

bool checkSameTree(tree* s, tree* t){
    if(!s && !t) return 1;
    if(!s || !t) return 0;
    
    return (s->val==t->val) && checkSameTree(s->left,t->left) && checkSameTree(s->right,t->right);
}

bool isSubtree(tree* s, tree* t){
    if(!t) return 1;
    
    if(!s) return 0;
    
    if(checkSameTree(s,t)) return 1;
    
    return  isSubtree(s->left,t) || isSubtree(s->right,t);
    
    
}
