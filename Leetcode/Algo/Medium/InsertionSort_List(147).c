/**************************************************************
147. Insertion Sort List

Sort a linked list using insertion sort.

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
**************************************************************/

typedef struct ListNode list;

void insert_node(list** head,list* node){
    list* current;
    if(!(*head) || ((*head)->val) >= node->val){
        node->next=*head;
        *head=node;
    } else{
        current=*head;
        
        while(current->next && current->next->val < node->val){
            current=current->next;
        }
        node->next=current->next;
        current->next=node;        
    }
}

list* insertionSortList(list* head){
    list* sorted=NULL;
    list* cur=head;
    
    while(cur){
        list* next=cur->next;
        
        insert_node(&sorted,cur);
        
        cur=next;       
    }
    
    head=sorted;
    return head;
}
