#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
struct node
{
	int val;
	struct node* next;
};
static int size=0;
void add_node_start(struct node** head, int val);
void add_node_mid(struct node** head, int pos, int val);
void printList(struct node* head);
struct node* form_list();
void delete_node(struct node** head,int val);
void search_element_iterative(struct node* head,int val);
bool search_element_recursive(struct node* head,int val);
void search_element(struct node* head);
int get_nth_node(struct node* head,int n);
void getNthfromlast(struct node* head,int n);
void printMid(struct node* head);
void loop(struct node* head);
void detect_loop_find_length_delete_loop(struct node* head);
void create_loop(struct node* head);
void sort(struct node* head);
void bubbleSort(struct node* head);
void swap(struct node *a,struct node *b);
void removeDup_sorted(struct node* head);
#endif
