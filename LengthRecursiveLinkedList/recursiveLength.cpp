#include <iostream> // This line includes the input/output stream library, allowing input and output operations.

struct Node {     
    int data;
    Node* next;

    // Constructor to initialize a Node with given value and nullptr as the next pointer
    Node(int val) : data(val), next(nullptr) {}
}; // This declares a struct named Node, representing a node in a linked list. It contains an integer data and a pointer next to the next node in the list. It also defines a constructor to initialize the data and next pointer of a node.

// Function to find the length of a linked list recursively
int findLengthRecursive(Node* head) {
    // Base case: if head is null, return 0
    if (head == nullptr)
        return 0;
    // Recursive call to find the length of the rest of the list
    return 1 + findLengthRecursive(head->next);
}
// This function findLengthRecursive finds the length of a linked list recursively. It takes a pointer to the head of the list as input. It first checks for the base case: if the head is null (indicating an empty list), it returns 0. Otherwise, it makes a recursive call to find the length of the rest of the list (starting from the next node) and adds 1 to it, representing the current node. This recursive process continues until it reaches the end of the list.

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next= new Node(6);


    // Find the length of the linked list recursively
    int length = findLengthRecursive(head);
    std::cout << "Length of the linked list: " << length << std::endl;

    // Deallocate memory to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

// This is the main function of the program. It creates a linked list with five nodes, each containing values 1 through 5. It then calls the findLengthRecursive function to calculate the length of the linked list recursively and prints the result. Finally, it returns 0, indicating successful execution of the program.
