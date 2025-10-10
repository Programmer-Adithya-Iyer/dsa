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

int main() {
	Node* head = nullptr;
}