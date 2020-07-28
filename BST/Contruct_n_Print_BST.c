#include <stdio.h>
#include <stdlib.h>

/************************
* 		BST Node
**********************/

typedef struct bst_node{
	int val;
	struct bst_node* left;
	struct bst_node* right;
}bst_node;

/*******************************
* ADD Node & Tree Construction
*******************************/

bst_node* add_newNode(int value){
	bst_node* new_node=(bst_node*)malloc(sizeof(bst_node));
	new_node->val=value;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

bst_node* insert_node(bst_node* node, int value){
	
	if(!node) return add_newNode(value);
	
	if(value < node->val){
		node->left = insert_node(node->left,value);
	}
	else{
		node->right = insert_node(node->right,value);
	}
	return node;
}

/*******************************
* 		Tree Traversals
*******************************/

void inorder(bst_node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \t", root->val); 
        inorder(root->right); 
    } 
} 

void postorder(bst_node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d \t", root->val);  
    }
} 

void preorder(bst_node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d \t", root->val); 
		preorder(root->left); 
        preorder(root->right); 
    } 
} 

/*******************************
*	Find Closest Value in Tree
*******************************/

int find_closest_Helper(bst_node* root,int target, int closest){
	
	if(abs(target - closest) > abs(root->val - target)){
		closest=root->val;
	}	
	
	if( (target < root->val) && root->left ){
		return find_closest_Helper(root->left,target,closest);
	}
	else if((target > root->val) && root->right){
		return find_closest_Helper(root->right,target,closest);
	}
	else{
		return closest;
	}
}


int find_closest(bst_node* root,int target){
	
	return find_closest_Helper(root,target,root->val);
	
}

int main(void){
	
	bst_node* root=NULL;
	root=insert_node(root,30);
	insert_node(root,5);
	insert_node(root,20);
	insert_node(root,40);
	insert_node(root,10);
	insert_node(root,50);	
	
	printf("Inorder: \n");
	inorder(root); 
	printf("\n");
	
	printf("Preorder: \n");
	preorder(root); 
	printf("\n");
	
	printf("Postorder: \n");
	postorder(root); 
	printf("\n");
	
	printf("Closest num: %d\n",find_closest(root,34));
	
	
	return 0;
}
