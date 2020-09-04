/***********************************************
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*************************************************/
typedef struct ListNode ls;

ls* swapPairs(ls* head){
    if(!head || !head->next) return head;
    
    ls* pre=head;
    ls* cur=head->next;
    ls* n=cur->next;
    head=cur;
    
    while(cur){
        if(n && n->next)
            pre->next=n->next;
        else pre->next=n;
        cur->next=pre;
        
        if(n && n->next)cur=n->next;
        else break;
        pre=n;
        n=cur->next;
    }
    return head;
}
