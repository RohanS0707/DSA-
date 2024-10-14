#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node* next;

};
struct node *head;
void display(struct node *t)
{
  while(t!=NULL)
   {
       printf("%d\n", t->data);
        t=t->next;
   }
}
int main()
{
      struct node *one= (struct node*)malloc(sizeof(struct node));
      struct node *two=(struct node*)malloc(sizeof(struct node));
      struct node *three=(struct node*)malloc(sizeof(struct node));
       struct node *four=(struct node*)malloc(sizeof(struct node));
       one->data=3;
       two->data=4;
       three->data=5;
       four->data=6;
        //printf("%d\n", one->data);
   //link the nodes
   head=one;
   one->next=two;
   two->next=three;
   three->next=four;
   four->next=NULL;
   //printf("%d\n", one->next->next->next->data);
   //struct node *t=head;
   display(head);
   //insertion at begining 
    struct node *new1=(struct node*)malloc(sizeof(struct node));
   new1->data=7;
   new1->next=head;
   head=new1;
   printf("After insertion at Beginning\n");
   display(head);
   struct node *t=head;
   while(t->next!=NULL)
   {
       //printf("%d\n", t->data);
        t=t->next;
   }
     struct node *new2=(struct node*)malloc(sizeof(struct node));
   new2->data=8;
   t->next=new2;
   new2->next=NULL;
    printf("After insertion at Ending\n");
   display(head);
   struct node *new3=(struct node*)malloc(sizeof(struct node));
   new3->data=9;
   t=head;
   while(t->data!=4)
   {
        t=t->next;
   }
   //printf("%d\n", t->data);
   new3->next=t->next;
   t->next=new3;
   printf("Insertion after 4\n");
   display(head);
    return 0;
}       


