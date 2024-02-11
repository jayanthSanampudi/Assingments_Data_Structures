#include <iostream>

// Definition of a Node structure for a singly linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a Node with given value and nullptr as next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the length of a linked list iteratively
int findLengthIterative(Node* head) {
    int length = 0;                      // Initialize length to 0
    Node* current = head;                // Start from the head of the list
    while (current != nullptr) {         // Loop until current reaches the end of the list
        length++;                        // Increment length for each node
        current = current->next;         // Move to the next node
    }
    return length;                       // Return the calculated length
}

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Find the length of the linked list
    int length = findLengthIterative(head);
    std::cout << "Length of the linked list: " << length << std::endl;  // Print the length of the linked list

    // Deallocate memory to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
