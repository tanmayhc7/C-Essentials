/****************************************
112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*************************************/
typedef struct TreeNode t;

void getSum(t* root, int target, int* sum,bool* ret){
    //Check if prev sum + child node value adds up to target
	if(!root->left && !root->right) {
        if((*sum) + root->val == target){
            *ret=1;
        }
        return;
    }
    //Add root->val to sum for intermediate nodes
    (*sum)+=root->val;
    
    if(root->left) {
        getSum(root->left,target,sum,ret);
    }
    if(root->right) {
        getSum(root->right,target,sum,ret);
    }
    
    //Subtract root->val before stack for current root clears
    (*sum)-=root->val;   
}

bool hasPathSum(t* root, int sum){
    if(!root) return 0;
    int s=0;
    bool ret=0;
    getSum(root,sum,&s,&ret);
    return ret;
}
