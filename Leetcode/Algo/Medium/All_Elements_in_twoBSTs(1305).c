/***************************************************
1305. All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
**************************************************/
typedef struct TreeNode t;

void get_Tree_elements(t* root,int** arr,int* size){
    if(!root) return;
    
    get_Tree_elements(root->left,arr,size);
    (*arr) = (int*)realloc((*arr),++(*size)*sizeof(int));
    (*arr)[*size-1]=root->val;
    get_Tree_elements(root->right,arr,size);    
}

int* mergeArrays(int* a1,int* a2, int s1, int s2){
    int* arr3=(int*)malloc((s1+s2)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<s1 && j<s2){
        if(a1[i] < a2[j]){
            arr3[k++]=a1[i++];
        } else{
            arr3[k++]=a2[j++];
            //arr3[k++]=a2[i++];
        }
    }
    while(j<s2){
            arr3[k++]=a2[j++];
        }
    while(i<s1){
            arr3[k++]=a1[i++];
        }
    return arr3;
}


int* getAllElements(t* root1, t* root2, int* rs){
    
    if(!root1 && !root2)  {
        *rs=0;
        return NULL;
    }
    int* arr1=NULL;
    int* arr2=NULL;
    int size1=0 ,size2=0;
    if(root1){
        get_Tree_elements(root1,&arr1,&size1);
        if(!root2){
            *rs=size1;
            return arr1;
        }
    }
    if(root2){
        get_Tree_elements(root2,&arr2,&size2);
        if(!root1){
            *rs=size2;
            return arr2;
        }
    }
    
    *rs=size1+size2;
    return mergeArrays(arr1,arr2,size1,size2);
}
