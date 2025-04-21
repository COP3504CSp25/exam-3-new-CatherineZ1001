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
		int* stats = new int[3];
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

			stats[0] = min;
			stats[1] = max;
			stats[2] = total/node_count;
			return stats;

		} else{
			stats[0] = 0;
			stats[1] = 0;
			stats[2] = 0;
			return stats;
		}
    }
    

private:
    Node* head = nullptr;
};
