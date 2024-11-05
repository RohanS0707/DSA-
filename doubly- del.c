#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void display(struct node* t) {
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}
// Function to delete at the beginning
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;  
    if (head != NULL) {
        head->prev = NULL;  // Set the previous pointer of the new head to NULL
    }
    free(temp);  
    printf("After deletion at the beginning:\n");
    display(head);
}

//Function to delete at the ending
void delete_at_end(){
	
 if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
	struct node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    if (t->prev != NULL) {
        t->prev->next = NULL; 
    } else {
        head = NULL;  
    }
    free(t);  // Free the last node
    printf("After deletion at the end:\n");
    display(head);
	
}
//Function to delete a after specific node
void delete_after_value(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* t = head;
    while (t != NULL && t->data != val) {
        t = t->next;
    }
    if (t != NULL && t->next != NULL) {
        struct node* to_delete = t->next;
        t->next = to_delete->next;
        if (to_delete->next != NULL) {
            to_delete->next->prev = t;
        }
        free(to_delete);  // Free the node after the target node
        printf("After deletion after node with value %d:\n", val);
        display(head);
    } else {
        printf("Node with value %d not found or no node after it.\n", val);
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
    printf("After insertion at the beginning:\n");
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

    // Deletions
    delete_at_beginning();   
    delete_at_end();         
    delete_after_value(4);   
    
    
    t = head;
    while (t != NULL) {
        struct node* temp = t;
        t = t->next;
        free(temp);
    }
    
    return 0;
}
