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
void add_node_mid(struct node** head,int pos, int val)
{
	struct node* temp=(struct node*) malloc(sizeof(struct node));
	temp->val=val;
	struct node* prev=*head;
	for(int i=0;i<pos;i++)
	{
		prev=prev->next;
	}
	temp->next=prev->next;
	prev->next=temp;
}

//print
void printList(struct node* head)
{
	if(!head)
	    {
		  printf("the head node cannot be NULL");
		  return;
		}
	while(head)
	{
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

void form_list()
{
	struct node* head = NULL;
	add_node_start(&head, 6);
	add_node_start(&head, 4);
	add_node_start(&head, 3);
	add_node_start(&head, 2);
	add_node_start(&head, 1);
	add_node_mid(&head,3,5);
	add_node_start(&head, 0);
	printList(head);
	delete_node(&head,4);
	printList(head);
}

void delete_node(struct node** head,int val)
{
	struct node* temp=*head;
	struct node* prev;
	if(!temp)
	{
		printf("head node not found"); return;
	}
	if (temp != NULL && temp->val == val)
	{
		*head = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL && temp->val != val)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;
	prev->next = temp->next;
	free(temp);
}
