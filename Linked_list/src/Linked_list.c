#include "Linked_list.h"
#include "time.h"

static node *head=NULL;
static int size=0;

void initHead(void){
	head=(node*) malloc(sizeof(node));
	head->next=NULL;
}

/************************************
 * 	ADD/DELETE VALUE FUNCTIONS
************************************/

void add_node_start(int val)
{
	node* temp= (node*) malloc(sizeof(node));
	temp->val=val;
	temp->next=head->next;
	head->next=temp;
	size++;
}

void add_node_mid(int pos, int val)
{
	node* temp= (node*) malloc(sizeof(node));
	temp->val=val;
	node* prev=head->next;
	for(int i=0;i<pos;i++)
	{
		prev=prev->next;
	}
	temp->next=prev->next;
	prev->next=temp;
	size++;
}

void printList(void)
{
	if(!(head->next))
	    {
		  printf("the head node cannot be NULL");
		  return;
		}
	node* temp= head->next;
	while(temp)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
	printf("\n");
}

void form_list()
{
	add_node_start(0);
	add_node_start(1);
	add_node_start(2);
	add_node_start(3);
	add_node_start(4);
	add_node_start(6);
	add_node_mid(5,5);
	printList();
	printf("size= %d\n",size);
	delete_node(6);
	printList();
	printf("size= %d\n",size);
}

void delete_node(int val)
{
	node* temp=head->next;
	node* prev=NULL;
	if(!temp)
	{
		printf("head node not found"); return;
	}
	if (temp != NULL && temp->val == val)
	{
		head->next = temp->next;
		free(temp); size--;
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
	free(prev);
}

/************************************
 * 	SEARCH ELEMENT FUNCTIONS
************************************/

void search_element_iterative(int val)
{
	node* temp=head->next;
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

bool search_element_recursive(node* temp,int val)
{
	if(!temp) return 0;
	if(temp->val==val) return 1;
	return search_element_recursive(temp->next,val);
}

int get_nth_node(int n)
{
	node* temp=head->next;
	while(temp)
	{
		temp=temp->next;
		n--;
		if(n==1) return temp->val;
	}
	return 0;
}

void getNthfromlast(int n)
{
	node* temp=head->next;
	node* ref=head->next;
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

void printMid(void)
{
	node* slow=head->next;
	node* fast=head->next;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	printf("\nMiddle element is %d",slow->val);
}


void search_element(void)
{
	search_element_recursive(head,5)? printf("5 found\n"): printf("5 not found\n");
	search_element_iterative(4);
	int n=4;
	int nth_node=get_nth_node(n);
	printf("\n%dth element is: %d",n,nth_node);
	getNthfromlast(n);
	printMid();
}

/************************************
 * 	LOOP FUNCTIONS
************************************/

void loop(void)
{
	create_loop();
	detect_loop_find_length_delete_loop();
}

void detect_loop_find_length_delete_loop(void)
{
	node* slow=head->next;
	node* fast=head->next;
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
		printf("\nLoop length= %d ",loop_length);
		slow->next=NULL;
		printf("\nLoop Deleted");
	}
	else
	{
		printf("\nLoop not detected");
	}
}

void create_loop(void)
{
	printf("\nCreating loop from ");
	node* node_1=head->next;
	node* node_2=head->next;
	while(node_1->next)
	{
		node_1=node_1->next;
	}
	time_t t;
	srand((unsigned) time(&t));
	int temp= rand() %size;
	printf("%dth element to the last element",temp);
	for(int i=0;i<temp;i++)
	{
		node_2=node_2->next;
	}
	node_1->next=node_2;

}

/************************************
 * 	SORT FUNCTIONS
************************************/
void sort(void)
{
	mergeSort(&head);
	//bubbleSort();
	printf("\nSorted List\n");
	printList();
}

void bubbleSort(void)
{

	if(!head) return;
	int swapped=1;
	node *cur=head->next;
	node *prev=head->next;
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

void swap(node *a,node *b)
{
	int temp=a->val;
	a->val=b->val;
	b->val=temp;
}

void mergeSort(void)
{
	node* h = head->next;
	node* a=NULL;
	node* b=NULL;

	if(!h || !h->next) return;

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(h, &a, &b);

    /* Recursively sort the sublists */
    mergeSort(&a);
    mergeSort(&b);

    /* answer = merge the two sorted lists together */
    head = SortedMerge(a, b);
}

node* SortedMerge(node* a,node* b)
{
	struct node* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->val <= b->val) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* Split the nodes of the given list into front and back halves,
   and return the two lists using the reference parameters.
   If the length is odd, the extra node should go in the front list.
   Uses the fast/slow pointer strategy. */
void FrontBackSplit(node* source,node** frontRef,node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}


int main(void) {
	initHead();
	form_list();
	search_element();
	loop();
	sort();
//	removeDup_sorted(head);
//	swapNodes(head,1,6);
	free(head);
	return 0;
}
