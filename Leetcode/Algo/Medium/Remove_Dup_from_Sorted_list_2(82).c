/*********************************************
82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*********************************************/

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head || !head->next) return head;
    
    struct ListNode* prev=NULL;
    struct ListNode* cur=head;
    struct ListNode* next=head->next;
    
    bool dup=0;
    bool dup_at_start=0;
    
    
    while(next){
        //if values are not the same, move the pointers to the right
        if(cur->val != next->val){
            dup=0;
            prev=cur;
            //modify head value if duplicates are from the start of the LL; just once
            if(!dup_at_start){
                head=prev;
                dup_at_start=1;
            }
            cur=next;
            next=next->next;
            continue;
        }
        
        dup=1;
        
        //if duplicate is found, keep on moving the next pointer till its NULL or new value is found
        while(next && cur->val == next->val){
            next=next->next;
        }
        
        if(prev) prev->next=next;
        cur=next;
        if(next) next=next->next;
    }
    
    //for cases with 1-1-1-2 ; i.e. only one unique value
    if(!prev && dup) return cur;
    //for cases with no unique values
    if(!prev) return NULL;
    
    return head;
}
