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

/******************************
  Level Order Traversal - BFS
******************************/

void printLevel(bst_node* root,int level){
	if(!root) return;
	
	if(level==1) printf("%d ",root->val);
	else{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
	
}

int get_height_of_tree(bst_node* root){
	if(!root) return 0;
	int l_ht=get_height_of_tree(root->left);
	int r_ht=get_height_of_tree(root->right);
	
	if(l_ht>r_ht) return l_ht+1;
	else return r_ht+1;
}

void printLevelOrder(bst_node* root){
	int height=get_height_of_tree(root);
	int i=1;
	for(;i<=height;i++){
		printLevel(root,i);
	}
}

int main(void){
	
	bst_node* root=NULL;
	root=insert_node(root,4);
	insert_node(root,2);
	insert_node(root,1);
	insert_node(root,3);
	insert_node(root,5);
	insert_node(root,6);	
	
	printLevelOrder(root);
	
	return 0;
}
