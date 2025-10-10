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

// Reverse a linked list
Node* reverse(Node* head) {
    Node* prevNode = nullptr;
    Node* currentNode = head;
    Node* temp = nullptr;

    while (currentNode) {
        temp = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = temp;
    }

    return prevNode;
}

Node* r_node_reverse(Node* prevNode, Node* currentNode) {
	Node* tempNode = currentNode->next;
	currentNode->next = prevNode;
	if (tempNode == nullptr) {
		return currentNode;
	}
	return r_node_reverse(currentNode, tempNode);
}

Node* r_reverse(Node* head) {
	Node* newHead = r_node_reverse(head, head->next);
	head->next = nullptr;
	return newHead;
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

// For printing single nodes - used by r_display function
void r_node_display (Node* currentNode) {
	std::cout << currentNode->value << " ";
	if ( currentNode->next != nullptr ) {
		r_node_display(currentNode->next);
	}
}

// For printing a linked list recursively.
void r_display(Node* head) {
	std::cout << "<Linked List> [ ";
	r_node_display(head);
	std::cout << "]" << std::endl;
}

int main() {
	Node* head = nullptr;

	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 5);
	head = insert(head, 10);
	display(head);

	head = r_reverse(head);

	r_display(head);
}