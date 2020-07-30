/*************************************************
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
**************************************************/

//Recursive
void helper(struct TreeNode* root, int** arr,int* size){  
    if(root){
        *size+=1;
        *arr=(int*)realloc(*arr,(*size)*sizeof(int));
        (*arr)[*size-1]=root->val;
        helper(root->left,arr,size);
        helper(root->right,arr,size);
    }
    else {
        return;
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret_arr=(int*)malloc(sizeof(int));
    *returnSize=0;
    helper(root,&ret_arr,returnSize);
    return ret_arr;    
}

//Iterative
void storeAndCollectLeftNodes(struct TreeNode* root, struct TreeNode*** stack, int* size, int** arr, int* returnSize)
{
    while(root)
    {
        *returnSize += 1;
        *arr = (int*)realloc(*arr, sizeof(int)*(*returnSize));
        (*arr)[*returnSize-1] = root->val;
        *size += 1;
        *stack = (struct TreeNode**)realloc(*stack, sizeof(struct TreeNode*)*(*size));
        (*stack)[*size-1] = root;
        root = root->left;
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(!root) 
    {   *returnSize=0;
        return NULL;}
    
    int* arr = (int*)malloc(sizeof(int));
    *returnSize = 0;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int size = 0;
    storeAndCollectLeftNodes(root, &stack, &size, &arr, returnSize);
    while(size)
    {
        root = stack[size-1];
        size--;
        if(root->right)
            storeAndCollectLeftNodes(root->right, &stack, &size, &arr, returnSize);
    }
    return arr;
}
 //MorrisTraversal
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(!root) return NULL;
    int* arr = (int*)malloc(sizeof(int));
    *returnSize = 0;
    while(root)
    {
        if(!root->left)
        {
            *returnSize += 1;
            arr = (int*)realloc(arr, sizeof(int)*(*returnSize));
            arr[*returnSize-1] = root->val;
            root = root->right;
        }
        else
        {
            struct TreeNode* pre = root->left;
            while(pre->right && pre->right!=root)
                pre = pre->right;
            if(!pre->right)
            {
                *returnSize += 1;
                arr = (int*)realloc(arr, sizeof(int)*(*returnSize));
                arr[*returnSize-1] = root->val;
                pre->right = root;
                root = root->left;
            }
            else
            {
                pre->right = NULL;
                root = root->right;
            }
        }
    }
    return arr;
}
