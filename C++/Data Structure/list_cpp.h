#pragma once
#include <iostream>
#ifndef LINKED_LIST_CPP_H_
#define LINKED_LIST_CPP_H_

template <class T>
class Node {
public:
	// member variables
	T data;
	Node<T>* link;

	// generators
	Node<T>() {
		data = 0;
		link = NULL;
	}
	Node<T>(T data) {
		this->data = data;
		link = NULL;
	}
};

template <class T>
class LinkedList {
	Node<T>* head;
	int length;

private:
	Node<T>* search_last_node() {
		Node<T>* p = head;
		while (p->link) {
			p = p->link; // go to the last node
		}
		return p;
	}
public:
	LinkedList<T>() {
		length = 0;
	}
	LinkedList<T>(T data) {
		add_node(data);
		length = 1;
	}

	inline Node<T>* create_node(T data) { // create new node
		return new Node<T>(data);
	}

	Node<T>* search_node(T data) { // search and return the address
		Node<T>* p = head;
		while (p->link) {
			if (p->data == data) {
				return p;
			}
			p = p->link;
		}

		return NULL; // if the data doesn't exist, return NULL
	}

	void add_node(Node<T>* prev, Node<T>* added) { // add a new node after particular node
		length++;
		Node<T>* next_node = prev->link;
		prev->link = added;
		added->link = next_node;
	}

	void add_node(Node<T>* added) { // add a new node into the tail of the list (by address)
		length++;
		if (head) {
			Node<T>* last = search_last_node();
			last->link = added;
		}
		else {
			head = added;
		}
	}

	void add_node(T data) { // add a new node into the tail of the list (by data)
		length++;
		if (head) {
			Node<T>* last = search_last_node();
			Node<T>* new_node = new Node<T>(data);
			last->link = new_node;
		}
		else {
			head = new Node<T>(data);
		}
	}

	void delete_node(Node<T>* deleted) {
		Node<T>* p = head;
		Node<T>* prev = NULL;

		if (!head) { // If the list is empty, throw error message
			throw "List is empty!";
		}
		else if (!deleted) { // If the value of argument is NULL, throw error message
			throw "No such that data found!";
		}

		while (p->link) { // search the data and save previous node's address
			if (p->link == deleted) {
				prev = p;
				break;
			}
			p = p->link;
		}

		prev->link = p->link; // bind the links
		delete p; // free the memory of p
		length--;
	}

	void delete_node(T data) {
		Node<T>* p = head;
		Node<T>* prev = NULL;

		if (!head) { // If the list is empty, throw error message
			throw "List is empty!";
		}

		while (p->link) { // search the data and save previous node's address
			if (!(p->link)) {
				throw "No such data found!";
			}
			if (p->link->data == data) {
				prev = p;
				p = p->link;
				break;
			}
			p = p->link;
		}

		prev->link = p->link; // bind the links
		delete p; // free the memory of p
		length--;
	}

	void print_list() {
		Node<T>* p = head;
		std::cout << "Length of this list: " << length << std::endl;
		while (p) {
			std::cout << p->data << ", ";
			p = p->link;
		}
		std::cout << std::endl;
	}
};

#endif // !LINKED_LIST_CPP_H_