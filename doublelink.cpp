#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void display(struct node* t) {
    while (t != NULL) {
        printf("%d\n", t->data);  // Corrected the format specifier
        t = t->next;
    }
}

int main() {
    // Create the nodes
    struct node* one = (struct node*)malloc(sizeof(struct node));
    struct node* two = (struct node*)malloc(sizeof(struct node));
    struct node* three = (struct node*)malloc(sizeof(struct node));
    struct node* four = (struct node*)malloc(sizeof(struct node));

    // Initialize the data
    one->data = 3;
    two->data = 4;
    three->data = 5;
    four->data = 6;

    // Link the nodes
    head = one;
    one->next = two;
    one->prev = NULL; 
    two->next = three; 
    two->prev = one;   
    three->next = four;
    three->prev = two;
    four->next = NULL;
    four->prev = three;

    // Display initial list
    printf("Initial List:\n");
    display(head);

    // Insertion at the beginning
    struct node* new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = 7;
    new1->next = head;
    new1->prev = NULL;
    head->prev = new1;
    head = new1;
    printf("After insertion at beginning:\n");
    display(head);

    // Insertion at the end
    struct node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    struct node* new2 = (struct node*)malloc(sizeof(struct node));
    new2->data = 8;
    t->next = new2;
    new2->prev = t;
    new2->next = NULL;
    printf("After insertion at the end:\n");
    display(head);

    // Insertion after the node with data 4
    struct node* new3 = (struct node*)malloc(sizeof(struct node));
    new3->data = 9;
    t = head;
    while (t != NULL && t->data != 4) {
        t = t->next;
    }
    if (t != NULL) {  // Check if t is not NULL
        new3->next = t->next;
        new3->prev = t;
        if (t->next != NULL) {
            t->next->prev = new3;
        }
        t->next = new3;
    }
    printf("After insertion after 4:\n");
    display(head);

    // Free allocated memory
    t = head;
    while (t != NULL) {
        struct node* temp = t;
        t = t->next;
        free(temp);
    }

    return 0;
}
