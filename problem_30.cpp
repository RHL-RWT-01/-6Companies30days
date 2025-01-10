#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    Node* linkdelete(Node* head, int m, int n) {
        Node* current = head;

        while (current) {
            // Skip m nodes
            for (int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }
            // If we've reached the end, return the list
            if (!current) {
                return head;
            }

            // Delete the next n nodes
            Node* temp = current->next;
            for (int i = 0; i < n && temp != nullptr; i++) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            // Connect the current node to the next remaining node
            current->next = temp;
            current = temp;
        }
        return head;
    }
};

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 2, n = 3;  // Skip 2 nodes, delete 3 nodes
    Node* head = createList(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Original list: ";
    printList(head);

    head = sol.linkdelete(head, m, n);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
