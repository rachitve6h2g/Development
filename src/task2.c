#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer to start of list
struct Node* head = NULL;

// Function to traverse and print the list
void traverse() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insert_at_beginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insert_at_end(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at a given position (0-based index)
void insert_at_position(int value, int position) {
    if (position == 0) {
        insert_at_beginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete node at a specific position (0-based index)
void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 0) {
        delete_at_beginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Main function to test
int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    traverse(); // 10 -> 20 -> 30 -> NULL

    insert_at_beginning(5);
    traverse(); // 5 -> 10 -> 20 -> 30 -> NULL

    insert_at_position(15, 2);
    traverse(); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    delete_at_position(2);
    traverse(); // 5 -> 10 -> 20 -> 30 -> NULL

    delete_at_beginning();
    traverse(); // 10 -> 20 -> 30 -> NULL

    delete_at_end();
    traverse(); // 10 -> 20 -> NULL

    return 0;
}

