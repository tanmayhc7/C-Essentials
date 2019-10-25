/*
 ============================================================================
 Name        : Linked_list.c
 Author      : Tanmay
 Version     :
 Copyright   : 
 ============================================================================
 */

#include "Linked_list.h"
int main() {
	struct node* head=form_list();
	search_element(head);
	loop(head);
	sort(head);
	removeDup_sorted(head);
	free(head);
	return 0;
}
