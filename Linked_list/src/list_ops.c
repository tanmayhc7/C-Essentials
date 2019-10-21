#include "Linked_list.h"
//add node at beginning
//we use pointer to pointer because we pass address of head node and do not return anything from the function

void add_node_start(struct node** head, int val)
{
	struct node* temp= (struct node*) malloc(sizeof(struct node));
	temp->val=val;
	temp->next=(*head);
	(*head)=temp;
}

//add node mid
void add_node_mid(struct node* prev,int val)
{
	if (!prev)
    {
	  printf("the given previous node cannot be NULL");
	  return;
	}
	struct node* temp=(struct node*) malloc(sizeof(struct node));
	temp->val=val;
	temp->next=prev->next;
	prev->next=temp;
}

//print
void printList(struct node* head)
{
	while(head)
	{
		printf("%d ",head->val);
		head=head->next;
	}
}

void form_list()
{
	struct node* head = NULL;
	add_node_start(&head, 6);
	add_node_start(&head, 7);
	add_node_start(&head, 12);
	add_node_start(&head, 10);
	printList(head);
}
