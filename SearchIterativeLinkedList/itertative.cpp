#include <iostream>
using namespace std;
// Definition of a Node structure for a singly linked list
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize a Node with given value and nullptr as next pointer
    Node(int val) : data(val), next(nullptr) {}
};    

// Function to search for a target value iteratively in a linked list
bool searchIterative(Node* head, int target) {
    Node* current = head; // Start from the head of the linked list
    // Iterate through the linked list until the current node becomes nullptr (end of list)
    while (current != nullptr) {
        // Check if the data of the current node matches the target value
        if (current->data == target)
            return true; // If found, return true
        current = current->next; // Move to the next node
    }
    return false; // If target not found in the entire linked list, return false
}

int main() {
    // Create a linked list with three nodes: 1 -> 2 -> 3
    Node* head = new Node(1);         // Head node with data 1
    head->next = new Node(2);         // Second node with data 2
    head->next->next = new Node(3);   // Third node with data 3

    int target = 2; // Target value to search for in the linked list
    // Check if the target value is present in the linked list using the searchIterative function
    if (searchIterative(head, target))
        cout << "Element " << target << " is present in the linked list." << std::endl;
    else
        cout << "Element " << target << " is not present in the linked list." << std::endl;

    return 0;
}
