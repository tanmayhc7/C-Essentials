#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int val;
	struct node* next;
}node;

void initHead(void);
void add_node_start(int val);
void add_node_mid(int pos, int val);
void printList(void);
void form_list(void);
void delete_node(int pos);

void search_element_iterative(int val);
bool search_element_recursive(node* temp,int val);
void search_element(void);
int get_nth_node(int n);
void getNthfromlast(int n);
void printMid(void);

void loop(void);
void detect_loop_find_length_delete_loop(void);
void create_loop(void);

void sort(void);
void bubbleSort(void);
void swap(node *a,node *b);
void mergeSort(void);
node* SortedMerge(node* a,node* b);
void FrontBackSplit(node* source,node** frontRef,node** backRef);
//void removeDup_sorted(node* head);
//void swapNodes(node* head,int x,int y);
#endif
