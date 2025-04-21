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

    int* getStats() const{
        Node* temp = head;
		if (head){
			int max = temp->data;
			int min = temp->data;
			int total = 0;
			int node_count = 0;
			while (temp != nullptr){
				if (temp->data > max) max = temp->data;
				if (temp->data < min) min = temp->data;
				total += temp->data;
				node_count ++;
				temp = temp->next;
			}

			int* stats = new int[min, max, total/node_count];
			return stats;
		} else{
			int* stats = new int[0, 0, 0];
			return stats;
		}
    }
    

private:
    Node* head = nullptr;
};
