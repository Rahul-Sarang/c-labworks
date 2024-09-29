#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->link = NULL;
    return node;
}

// Function to insert a new node at the front of the linked list
void InsertBegin(Node** head, int data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->link = *head;
    *head = new_node;
    printf("Node %d inserted at the beginning\n", data);
}

// Function to insert a new node at the end of the linked list
void InsertEnd(Node** head, int data) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
    printf("Node %d inserted at the end\n", data);
}

// Function to insert a new node at a specific position in the linked list
void InsertAny(Node** head, int data, int position) {
    Node* new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (position == 0) {
        new_node->link = *head;
        *head = new_node;
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            if (temp->link == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
    printf("Node %d inserted at position %d\n", data, position);
}

// Function to delete a node from the front of the linked list
void Delete1st(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->link;
    printf("Node %d deleted from the front\n", temp->data);
    free(temp);
}

// Function to delete a node from the end of the linked list
void DeleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->link == NULL) {
        printf("Node %d deleted from the end\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        printf("Node %d deleted from the end\n", temp->link->data);
        free(temp->link);
        temp->link = NULL;
    }
}

// Function to delete a node at a specific position in the linked list
void DeleteAny(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->link;
        printf("Node %d deleted at position %d\n", temp->data, position);
        free(temp);
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            if (temp->link == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp = temp->link;
        }
        if (temp->link == NULL) {
            printf("Position out of range\n");
            return;
        }
        Node* node_to_delete = temp->link;
        temp->link = temp->link->link;
        printf("Node %d deleted at position %d\n", node_to_delete->data, position);
        free(node_to_delete);
    }
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    int choice;
    while (true) {
        printf("Linked List Menu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int data;
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertBegin(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                int position;
                printf("Enter position to insert: ");
                scanf("%d", &position);
                InsertAny(&head, data, position);
                break;
            case 4:
                Delete1st(&head);
                break;
            case 5:
                DeleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                DeleteAny(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
