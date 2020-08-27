#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 10
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
bst_node** create_Queue(int* front,int* rear){
	bst_node **queue=(bst_node**)malloc(Q_SIZE*sizeof(bst_node*));
	*front=0;
	*rear=0;
	return queue;
}

void enQueue(bst_node **q,int* r,bst_node* root){
	q[(*r)++]=root;
}

bst_node* deQueue(bst_node **q,int* f){
	return q[(*f)++];
}

void printLevelOrder(bst_node *root){
	int front,rear;
	bst_node** q=create_Queue(&front,&rear);
	
	bst_node* temp=root;
	while(temp){
		printf("%d ",temp->val);
		
		if(temp->left) enQueue(q,&rear,temp->left);
		if(temp->right) enQueue(q,&rear,temp->right);
		
		temp=deQueue(q,&front);		
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
