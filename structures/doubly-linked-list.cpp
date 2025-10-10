#include <iostream>

// Node for Doubly Linked List
class Node {
public:
	int value;
	Node* prev;
	Node* next;
};

// Inserting to Doubly Linked List
Node* insert(Node* head, int x) {
	Node* newNode = new Node();
	newNode->value = x;
	newNode->prev = nullptr;
	newNode->next = head;

	if (head != nullptr) {
		head->prev = newNode;
	}

	return newNode;
}

// Inserting at arbitary index in linked list
Node* put (Node* head, int x, int index) {
	Node* newNode = new Node();

	if (index == 0) {
		return insert(head, x);
	}

	Node* currentNode = head;
	newNode->value = x;

	int counter = 0;
	while (counter < index - 1 && currentNode != nullptr) {
		currentNode = currentNode->next;
		counter++;
	}

	Node* tempNode = currentNode->next;
	currentNode->next = tempNode->prev = newNode;
	newNode->prev = currentNode;
	newNode->next = tempNode;

	return head;
}

// Pushing to Doubly Linked List
Node* push (Node* head, int x) {
	Node* newNode = new Node();
	Node* currentNode = head;

	newNode->value = x;
	
	if (head == nullptr) {
		newNode->next = newNode->prev = nullptr;
		return newNode;
	} 

	while(currentNode->next != nullptr) {
		currentNode = currentNode->next;
	}

	currentNode->next = newNode;
	newNode->prev = currentNode;
	newNode->next = nullptr;

	return head;
}

// Display the linked list
void display(Node* head) {
    std::cout << "<Linked List> [ ";
    Node* temp = head;
    while (temp) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

int main() {
	Node* head = nullptr;

	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	display(head);
	
	head = put(head, 6, 2);
	display(head);
}