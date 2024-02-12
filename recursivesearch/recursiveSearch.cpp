#include <iostream> // This line includes the input/output stream library, allowing input and output operations.

struct Node {
    int data;
    Node* next;

    // Constructor to initialize a Node with given value and nullptr as the next pointer
    Node(int val) : data(val), next(nullptr) {}
}; // This declares a struct named Node, representing a node in a linked list. It contains an integer data to store the value of the node and a pointer next to point to the next node in the list. It also defines a constructor to initialize the data and next pointer of a node.

bool searchRecursive(Node* head, int target) {
    if (head == nullptr)
        return false;
    if (head->data == target)
        return true;
    return searchRecursive(head->next, target);
} // This function searchRecursive searches for a target element in a linked list recursively. It takes a pointer to the head of the list and the target value as input. It first checks for the base case: if the head is null (indicating an empty list), it returns false. Then, it checks if the data of the current node equals the target value. If it does, it returns true. Otherwise, it makes a recursive call to search for the target in the rest of the list (starting from the next node).

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next= new Node(4);

    int target = 3;
    if (searchRecursive(head, target))
        std::cout << "Element " << target << " is present in the linked list." << std::endl;
    else
        std::cout << "Element " << target << " is not present in the linked list." << std::endl;

    // Deallocate memory to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
} // This is the main function of the program. It creates a linked list with three nodes, each containing values 1 through 3. It then searches for the target element 2 in the linked list using the searchRecursive function. If the element is found, it prints a message indicating its presence; otherwise, it prints a message indicating its absence. Finally, it deallocates memory to avoid memory leaks and returns 0, indicating successful execution of the program.
