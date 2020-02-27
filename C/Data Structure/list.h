#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

// list node structure
typedef struct list_node* list_link;
typedef struct list_node {
	int idx;
	int data;
	
	list_link next;
} list_node;

list_link head; // save the address of the starting point

/***** Linked list functions *****/

// dynamic allocate a new node
list_link create_node(int data) {
	list_link created_node; // pointer variable that saves the address of newly created node
	int new_idx = -1; // index of newly created node

	new_idx += 1; // determine the index - next number of last index

	// dynamic allocate and initialize
	created_node = (list_link)malloc(sizeof(list_node));
	created_node->data = data;
	created_node->idx = new_idx;
	created_node->next = NULL;
	return created_node;
}

// function that adds a node after particular node
void add_node(list_link added_node, list_link prev_node) {
	list_link next_node = prev_node->next;
	prev_node->next = added_node;
	added_node->next = next_node;
}

// function that adds a node to the end of the list
void add_node_back(list_link added_node) {
	list_link p = head; // temp list pointer p

	if (!head) {
		head = added_node;
		return;
	}
	
	// move to the end of the list
	while (p->next) {
		p = p->next;
	}

	// bind the new node to the end of the list
	p->next = added_node;
}

// search and return a particular node by index
list_link search_node_by_idx(int idx) {
	list_link p = head; // temp list pointer p

	// search the list
	while (p->next) {
		if (p->idx == idx) {
			return p;
		}
		p = p->next; // search next node
	}

	return NULL; // if the index isn't searched, return NULL
}

// search and return a particular node by data
list_link search_node_by_data(int data) {
	list_link p = head; // temp list pointer p

	// search the list
	while (p->next) {
		if (p->data == data) {
			return p;
		}
		p = p->next; // search next node
	}

	return NULL; // if the data isn't searched, return NULL
}

void delete_node(list_link deleted_node) {
	list_link p = head;
	list_link previous_node = NULL; // pointer variable that saves the address of the node before the deleted node

	if (!deleted_node) { // if arg got NULL, terminate the function
		return;
	}

	// search the list
	while (p->next) {
		if (p->next == deleted_node) {
			previous_node = p;
			break;
		}
		p = p->next;
	}

	previous_node->next = deleted_node->next; // bind the nodes before and after the deleted node
	free(deleted_node); // delete node (free allocation)
}

void delete_all_list() {
	list_link next = head;
	
}

void print_list() {
	list_link p = head;

	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
}