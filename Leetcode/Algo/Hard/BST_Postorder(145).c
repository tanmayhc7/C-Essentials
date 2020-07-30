/***************************************
145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
*************************************/

//Recursive
void helper(struct TreeNode* root, int** arr,int* size){  
    if(root){
        helper(root->left,arr,size);
        helper(root->right,arr,size);
        *size+=1;
        *arr=(int*)realloc(*arr,(*size)*sizeof(int));
        (*arr)[*size-1]=root->val;
    }
    else {
        return;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret_arr=(int*)malloc(sizeof(int));
    *returnSize=0;
    helper(root,&ret_arr,returnSize);
    return ret_arr;
}

//Iterative
//AC - 0ms;
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(!root) return NULL;
    int* arr = (int*)malloc(sizeof(int));
    *returnSize = 0;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int size = 0;
    stack[size++] = root;
    while(size)
    {
        root = stack[size-1];
        size--;
        *returnSize += 1;
        arr = (int*)realloc(arr, sizeof(int)*(*returnSize));
        arr[*returnSize-1] = root->val;
        if(root->left)
        {
            size++;
            stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*)*size);
            stack[size-1] = root->left;
        }
        if(root->right)
        {
            size++;
            stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*)*size);
            stack[size-1] = root->right;
        }
    }
    size = *returnSize;
    for(int i = 0; i < size/2; i++)//reverse the previous result - mid+right+left customized preorder;
    {
        int t=arr[i]; arr[i]=arr[size-i-1]; arr[size-i-1]=t;
    }
    return arr;
}

#define LEN 1000
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(!root) return NULL; 
    int* arr = (int*)malloc(sizeof(int)*LEN);
    *returnSize = 0;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*LEN);
    int size = 0;
    stack[size++] = root;
    struct TreeNode* pre = NULL; //either the parent or the child of cur;
    while(size)
    {
        struct TreeNode *cur = stack[size-1];
        if(!pre || pre->left==cur || pre->right==cur) //pushing only one child to the stack each time;
        //from the current node to collect the children;
        {
            if(cur->left)
                stack[size++] = cur->left;
            else 
            {
                if(cur->right)
                    stack[size++] = cur->right;
                else
                {
                    *returnSize += 1;
                    arr[*returnSize-1] = cur->val;
                    size--;
                }
            }
        }
        //start to collect the right part from bottom to top;
        else if(cur->left == pre) //left part has been handled;
        {
            if(cur->right)
                stack[size++] = cur->right;
            else
            {
                *returnSize += 1;
                arr[*returnSize-1] = cur->val;
                size--;
            }
        }
        else if(cur->right == pre)
        {
            *returnSize += 1;
            arr[*returnSize-1] = cur->val;
            size--;
        }
        pre = cur;
    }
    return arr;
}


