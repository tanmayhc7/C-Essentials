#include "Linked_list.h"
//add node at beginning
//we use pointer to pointer because we pass address of head node and do not return anything from the function

void add_node_start(struct node** head, int val)
{
	struct node* temp= (struct node*) malloc(sizeof(struct node));
	temp->val=val;
	temp->next=(*head);
	(*head)=temp;
	size++;
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
	size++;
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

struct node* form_list()
{
	struct node* head = NULL;
	add_node_start(&head, 6);
	add_node_start(&head, 4);
	add_node_start(&head, 3);
	add_node_start(&head, 2);
	add_node_start(&head, 1);
	add_node_mid(&head,3,5);
	add_node_start(&head, 0);
	printList(head); //0123456
	printf("size= %d\n",size);
	delete_node(&head,4);
	printList(head);//012356
	printf("size= %d\n",size);
	return head;
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
	size--;
	free(temp);
}

void search_element_iterative(struct node* head,int val)
{
	struct node* temp=head;
	bool flag=0;
	while(temp)
	{
		if(temp->val==val)
		{
			flag=1;break;
		}
		temp=temp->next;
	}
	(flag==1) ? printf("%d found",val) : printf("%d not found",val);
}

bool search_element_recursive(struct node* head,int val)
{
	if(!head) return 0;
	if(head->val==val) return 1;
	return search_element_recursive(head->next,val);
}

void search_element(struct node* head)
{
	search_element_recursive(head,5)? printf("5 found\n"): printf("5 not found\n");
	search_element_iterative(head,4);
}
