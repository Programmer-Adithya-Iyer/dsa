#include <iostream>

class Node {
public:
	int value;
	Node* next;
};

// Pushing to the linked list
Node* push(Node* head, int x) {
    Node* newNode = new Node();
    newNode->value = x;
    newNode->next = NULL;

    if (head == NULL) {
        // If list is empty, new node becomes the head
        return newNode;
    }

    Node* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;

    return head;
}

// Pushing to the linked list at 0th index
Node* insert(Node* head, int x) {
	Node* newNode = new Node();
	newNode->value = x;
	if (head == NULL) {
		newNode->next = NULL;
	} else {
		newNode->next = head;
	}

	return newNode;
}

// Pushing at an arbitrary index
Node* put(Node* head, int x, int index = 0) {
    if (index == 0) return insert(head, x);

    Node* currentNode = head;
    int counter = 0;

    // Move to node just before position for insertion
    while (counter < index - 1 && currentNode != nullptr) {
        currentNode = currentNode->next;
        counter++;
    }

    if (currentNode == nullptr) {
        std::cout << "Index out of range. Insertion failed." << std::endl;
        return head;
    }

    Node* newNode = new Node();
    newNode->value = x;
    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return head;
}

// Popping from the linked list at a given index
Node* pop(Node* head, int index) {
    if (head == nullptr) {
        std::cout << "List is empty. Nothing to pop." << std::endl;
        return head;
    }

    // If removing the head node
    if (index == 0) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* currentNode = head;
    int counter = 0;

    // Move to node just before the one to delete
    while (counter < index - 1 && currentNode->next != nullptr) {
        currentNode = currentNode->next;
        counter++;
    }

    // If index is out of range
    if (currentNode->next == nullptr) {
        std::cout << "Index out of range. Pop failed." << std::endl;
        return head;
    }

    Node* nodeToDelete = currentNode->next;
    currentNode->next = nodeToDelete->next;
    delete nodeToDelete;

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

	head = insert(head, 10);
	head = insert(head, 20);
	head = pop(head, 0);

	display(head);
}