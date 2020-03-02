#pragma once
#include <iostream>
#ifndef DOUBLY_LINKED_LIST_CPP_H_
#define DOUBLY_LINKED_LIST_CPP_H_

template <class T>
class Node {
public:
    // member variables
    T data;

    // needs 2 pointer variables for doubly linked list
    Node<T>* next;
    Node<T>* prev;

    // generators
    Node<T>() {
        next = NULL;
        prev = NULL;
    }
    Node<T>(T data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class LinkedList {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    int length;

private:
    Node<T>* search_last_node() {
        Node<T>* p = head;
        while (p->next) {
            p = p->next; // go to the last node
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

    Node<T>* getHead() { return head; }
    Node<T>* getTail() { return tail; }

    inline Node<T>* create_node(T data) { // create a new node
        return new Node<T>(data);
    }

    Node<T>* search_node_from_head(T data) { // search and return the address, starts from head
        Node<T>* p = head;
        while (p->next) {
            if (p->data == data) {
                return p;
            }
            p = p->next;
        }

        return NULL; // if the data doesn't exist, return NULL
    }

    Node<T>* search_node_from_tail(T data) { // search and return the address, starts from tail
        Node<T>* p = tail;
        while (p->prev) {
            if (p->data == data) {
                return p;
            }
            p = p->prev;
        }

        return NULL; // if the data doesn't exist, return NULL
    }

    void add_node(Node<T>* added) { // add a new node (sorted)
        if (!head || added->data >= tail->data) { // if there is a node or new-comer is bigger than tail, add it to the end
            add_node_back(added);
        }
        else {
            length++; // else, insert it in sorted way (insertion sort style)
            Node<T>* p = head;
            while (p->next) {
                if (p->next->data >= added->data && p->data <= added->data) {
                    added->next = p->next;
                    added->prev = p;
                    p->next->prev = added;
                    p->next = added;
                    break;
                }
                p = p->next;
            }
        }
    }

    void add_node_behind_node(Node<T>* prev, Node<T>* added) { // add a new node after particular node
        length++;
        Node<T>* next_node = prev->next;
        prev->next = added;
        added->next = next_node;
    }

    void add_node_back(Node<T>* added) { // add a new node into the tail of the list (by address)
        length++;
        if (head) {
            tail->next = added;
            added->prev = tail;
            tail = added;
        }
        else {
            head = added;
            tail = added;
        }
    }

    void add_node_back(T data) { // add a new node into the tail of the list (by data)
        length++;
        if (head) {
            Node<T>* new_node = new Node<T>(data);
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        else {
            head = new Node<T>(data);
            tail = head;
        }
    }

    void delete_node(Node<T>* deleted) {
        Node<T>* p = head;
        Node<T>* prev_node = NULL;

        if (!head) { // If the list is empty, throw error message
            throw "List is empty!";
        }
        else if (!deleted) { // If the value of argument is NULL, throw error message
            throw "No such that data found!";
        }

        while (p->next) { // search the data and save previous node's address
            if (p->next == deleted) {
                prev_node = p;
                break;
            }
            p = p->next;
        }

        // bind the links
        prev_node->next = p->next;
        p->next->prev = prev_node;

        delete p; // free the memory of p
        length--;
    }

    void delete_node(T data) {
        Node<T>* p = head;
        Node<T>* prev_node = NULL;

        if (!head) { // If the list is empty, throw error message
            throw "List is empty!";
        }

        while (p->next) { // search the data and save previous node's address
            if (!(p->next)) {
                throw "No such data found!";
            }
            if (p->next->data == data) {
                prev_node = p;
                p = p->next;
                break;
            }
            p = p->next;
        }

        prev_node->next = p->next; // bind the links
        p->next->prev = prev_node;

        delete p; // free the memory of p
        length--;
    }

    void print_list_forward() {
        Node<T>* p = head;
        std::cout << "Length of this list: " << length << std::endl << std::endl;
        while (p) {
            std::cout << p->data << std::endl << '|' << std::endl;
            p = p->next;
        }
        std::cout << std::endl;
    }

    void print_list_backward() {
        Node<T>* p = tail;
        std::cout << "Length of this list: " << length << std::endl << std::endl;
        while (p) {
            std::cout << p->data << std::endl << '|' << std::endl;
            p = p->prev;
        }
        std::cout << std::endl;
    }
};

#endif // !DOUBLY_LINKED_LIST_CPP_H_
