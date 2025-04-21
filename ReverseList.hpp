#pragma once

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    LinkedList reverseList() const {
        Node* temp = head;
		LinkedList newlist = {};

		while (temp != nullptr){
			newlist.addHead(temp->data);
			temp = temp->next;
		}

		return newlist;
    }

    Node* head = nullptr;
};
