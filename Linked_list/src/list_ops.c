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
	add_node_start(&head, 0);
	add_node_start(&head, 1);
	add_node_start(&head, 2);
	add_node_start(&head, 3);
	add_node_start(&head, 4);
	add_node_mid(&head,3,5);
	add_node_start(&head, 2);
	add_node_start(&head, 6);
	add_node_start(&head, 3);
	add_node_start(&head, 0);
	printList(head);
	printf("size= %d\n",size);
	delete_node(&head,4);
	printList(head);
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
	int n=4;
	int nth_node=get_nth_node(head,n);
	printf("\n%dth element is: %d",n,nth_node);
	getNthfromlast(head,n);
	printMid(head);
}

int get_nth_node(struct node* head,int n)
{
	struct node* temp=head;
	while(temp)
	{
		temp=temp->next;
		n--;
		if(n==0) return temp->val;
	}
	return 0;
}

void getNthfromlast(struct node* head,int n)
{
	struct node* temp=head;
	struct node* ref=head;
	int backup=n;
	while(n)
	{
		ref=ref->next;
		n--;
	}
	while(ref)
	{
		temp=temp->next;
		ref=ref->next;
	}
	printf("\n%dth element from the end is %d",backup,temp->val);
}

void printMid(struct node* head)
{
	struct node* slow=head;
	struct node* fast=head;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	printf("\nMiddle element is %d",slow->val);
}

void loop(struct node* head)
{
	create_loop(head);
	detect_loop_find_length_delete_loop(head);
}

void detect_loop_find_length_delete_loop(struct node* head)
{
	struct node* slow=head;
	struct node* fast=head;
	bool flag=0;
	while(fast && slow && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			flag=1;break;
		}
	}
	int loop_length=0;
	if(flag)
	{
		while(slow->next!=fast)
			{
				slow=slow->next;
				loop_length++;
			}
		printf("\nLoop length= %d",loop_length);
		slow->next=NULL;
		printf("\nLoop Deleted");
	}
	else
	{
		printf("\nLoop not detected");
	}
}

void create_loop(struct node* head)
{
	printf("\nCreating loop");
	struct node* node_1=head;
	struct node* node_2=head;
	while(node_1->next)
	{
		node_1=node_1->next;
	}
	time_t t;
	srand((unsigned) time(&t));
	int temp= rand() %size;
	for(int i=0;i<temp;i++)
	{
		node_2=node_2->next;
	}
	node_1->next=node_2;

}

void sort(struct node* head)
{
	bubbleSort(head);
	printf("\nSorted List\n");
	printList(head);
}

void bubbleSort(struct node* head)
{

	if(!head) return;
	int swapped=1;
	struct node*cur=head;
	struct node*prev=head;
	while(swapped && prev->next)
	{
		swapped=0;
		while(cur->next)
		{
			if(cur->val > cur->next->val)
			{
				//swap data and not nodes
				swap(cur,cur->next);
				swapped=1;
			}
			cur=cur->next;
		}
		cur=head;
		prev=prev->next;
	}
}

void swap(struct node *a,struct node *b)
{
	int temp=a->val;
	a->val=b->val;
	b->val=temp;
}

void removeDup_sorted(struct node* head)
{
	struct node* cur=head->next;
	struct node* prev=head;
	struct node* temp=NULL;
	printf("\nRemoving duplicates:\n");
	while(cur)
	{
		if(prev->val==cur->val)
		{
			temp=cur;
			cur=cur->next;
			prev->next=cur;
			free(temp);
		}
		else
		{
			cur=cur->next;
			prev=prev->next;
		}
	}
	printList(head);
}
