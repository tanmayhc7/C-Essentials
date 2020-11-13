/**********************************************************8
637. Average of Levels in Binary Tree

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:
The range of node's value is in the range of 32-bit signed integer.
**************************************************************/

//Use BFS and get sum of node values at each level and divide by num of nodes

int get_ht(struct TreeNode* root){
    if(!root) return 0;
    
    int left_ht = get_ht(root->left);
    int right_ht = get_ht(root->right);
    
    if(left_ht > right_ht) return left_ht+1;
    return right_ht+1;    
}

void helper(struct TreeNode* root,double* ret,int size,int* level_nodes,int iterator){
    if(!root) return;
    
    if(size==1) {
        ret[iterator]+=root->val;
        (*level_nodes)++;
    }else{
		helper(root->left,ret,size-1,level_nodes,iterator);
		helper(root->right,ret,size-1,level_nodes,iterator);
	}
    
}


double* averageOfLevels(struct TreeNode* root, int* returnSize){
    
    if(!root){
        *returnSize=0;
        return NULL;
    }
    
    int tree_ht=get_ht(root);
    *returnSize=tree_ht;
    
    double* ret=(double*)calloc(tree_ht,sizeof(double));
    
    int num=0;
    ret[0]=root->val;
    
    for(int i=2;i<=tree_ht;i++){
        helper(root,ret,i,&num,i-1);
        ret[i-1]/=num;
        num=0;
    }
        
    
    return ret;
}
