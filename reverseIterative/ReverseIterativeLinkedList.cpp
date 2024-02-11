#include <iostream> // This line includes the input/output stream library, which allows input and output operations.

struct Node {
    int data;
    Node* next;

    // Constructor to initialize a Node with given value and nullptr as the next pointer
    Node(int val) : data(val), next(nullptr) {}
}; // This declares a struct named Node, representing a node in a linked list. It contains an integer data to store the value of the node and a pointer next to point to the next node in the list. It also defines a constructor to initialize the data and next pointer of a node.

Node* reverseLinkedListIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        // Store the next node in the list
        next = current->next;
        // Reverse the link of the current node
        current->next = prev;
        // Move prev and current pointers one step forward
        prev = current;
        current = next;
    }

    // 'prev' now points to the new head of the reversed list
    return prev;
} // This function reverseLinkedListIterative reverses a linked list iteratively. It takes a pointer to the head of the list as input. It initializes three pointers: prev to keep track of the previous node, current to traverse the list, and next to store the next node in the list. It iterates through the list, reversing the links of each node. Finally, it returns the new head of the reversed list.

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
} // This function printLinkedList prints the elements of a linked list. It takes a pointer to the head of the list as input. It traverses the list using a while loop, printing the data of each node. After printing all elements, it adds a newline character to the output.

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    // Reverse the linked list iteratively
    head = reverseLinkedListIterative(head);

    std::cout << "Reversed linked list: ";
    printLinkedList(head);

    // Deallocate memory to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
} // This is the main function of the program. It creates a linked list with five nodes, each containing values 1 through 5. It then prints the original linked list using the printLinkedList function. After that, it reverses the linked list iteratively using the reverseLinkedListIterative function and prints the reversed linked list. Finally, it deallocates memory to avoid memory leaks and returns 0, indicating successful execution of the program.
