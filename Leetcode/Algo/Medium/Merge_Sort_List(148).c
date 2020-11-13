/*************************************************************************
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order in O(n logn) time and O(1) memory (i.e. constant space).

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
****************************************************************************/
typedef struct ListNode list;

void frontbackSplit(list* head,list** a,list** b){
    list* slow=head;
    list* fast=head->next;
    
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *a=head;
    *b=slow->next;
    slow->next=NULL;
}

list* sortedMerge(list* a,list* b){
      
    if(!a) return b;
    if(!b) return a;
        
    list* result=NULL;    
    
    if(a->val <= b->val){
        result=a;
        result->next=sortedMerge(a->next,b);
    } else{
        result=b;
        result->next=sortedMerge(a,b->next);
    }
    
    return result;   
}

void mergeSort(list** head_ref){
    list* head_backup=*head_ref;
    if(!head_backup || !head_backup->next){
        return;
    }
    
    list* a;
    list* b;
    
    frontbackSplit(head_backup,&a,&b);
    
    mergeSort(&a);
    mergeSort(&b);
    
    *head_ref=sortedMerge(a,b);
}


list* sortList(list* head){
    mergeSort(&head);
    return head;
}
