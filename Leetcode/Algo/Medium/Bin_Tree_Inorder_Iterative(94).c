/****************
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*******************/
//Stack node
struct sNode 
{ 
  struct TreeNode *t; 
  struct sNode *next; 
}; 

void push(struct sNode** top_ref, struct TreeNode *t) 
{ 
  /* allocate tNode */
  struct sNode* new_tNode = 
            (struct sNode*) malloc(sizeof(struct sNode)); 
 
  /* put in the data  */
  new_tNode->t  = t; 
  
  /* link the old list off the new tNode */
  new_tNode->next = (*top_ref);    
  
  /* move the head to point to the new tNode */
  (*top_ref)    = new_tNode; 
} 
  
/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct sNode *top) 
{ 
   return (top == NULL)? 1 : 0; 
}    
  
/* Function to pop an item from stack*/
struct TreeNode *pop(struct sNode** top_ref) 
{ 
  struct TreeNode *res; 
  struct sNode *top; 
  
  /*If sNode is empty then error */
  if(isEmpty(*top_ref)) 
  { 
     printf("Stack Underflow \n"); 
     return NULL;
  } 
  else
  { 
     top = *top_ref; 
     res = top->t; 
     *top_ref = top->next; 
     free(top); 
     return res; 
  } 
} 

int* inorderTraversal(struct TreeNode* root, int* retS){
    if(!root) {
        *retS=0;
        return NULL;
    }
    
    int size=0;
    struct TreeNode* cur=root;
    struct sNode *s = NULL;  /* Initialize stack s */
    bool done=0;
    int* result=(int*)malloc((++size)*sizeof(int));
    while(!done){
        if(cur){
            push(&s, cur); 
            cur=cur->left;
        } else{ 
            if (!isEmpty(s)){ 
                cur = pop(&s);
                            
                result=(int*)realloc(result,size*sizeof(int));
                result[size-1]=cur->val;
                size++;
                cur = cur->right; 
            } else{
                done = 1;          
            }
        } 
    }
    *retS=size-1;
    return result;
}
