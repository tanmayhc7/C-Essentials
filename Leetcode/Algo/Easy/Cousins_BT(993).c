/*************************************************
993. Cousins in Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
**************************************************/
int get_ht(struct TreeNode* root){
    if(!root) return 0;
    
    int left=get_ht(root->left);
    int right=get_ht(root->right);
    
    if(left>right) return left+1;
    return right+1;
}

void helper(struct TreeNode* root, int x, int y,int level,bool* x_found,bool* y_found,int* x_parent,int* y_parent){
    if(!root) return;
    
    if(level==0){
        if(root->val==x){
            (*x_found)=1; return;
        }
        if(root->val==y){
            (*y_found)=1;
        }
    } else{
        helper(root->left ,x,y,level-1,x_found,y_found,x_parent,y_parent);
        helper(root->right,x,y,level-1,x_found,y_found,x_parent,y_parent);
        if((*y_found)) {
            (*y_parent)=root->val;
            (*y_found)=0;   
        }
        if((*x_found)){
          (*x_parent)=root->val;
          (*x_found)=0;  
        }
    }
    
}

bool isCousins(struct TreeNode* root, int x, int y){
    
    int ht=get_ht(root);
    bool x_f=0,y_f=0;
    int x_par=0,y_par=0;
	
	//start from level 2 to exclude children of the root
    for(int i=2;i<=ht;i++){
        
		helper(root,x,y,i,&x_f,&y_f,&x_par,&y_par);
		
		//if x is found and y isnt on same level(or vice versa) 
        if( (!x_par && y_par) || (x_par && !y_par)) return 0;    
    }
    //this case will be for children of the root
    if((!x_par && !y_par)) return 0;
    return !(x_par==y_par);
}
