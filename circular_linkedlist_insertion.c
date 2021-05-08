#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insert_at_first(struct node *head, int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=val;
    ptr->next=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    return ptr;

}

void insert_at_last(struct node *head, int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=val;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;

}

void insert_in_between(struct node *head, int val, int index){
    int i=0;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=val;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
}

void display(struct node *head){
    struct node *p=head;
    printf("%d\n",p->data);
    p=p->next;
    while(p!=head){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main(){
    struct node * head= (struct node *) malloc(sizeof(struct node));
    struct node * second= (struct node *) malloc(sizeof(struct node));
    struct node * third= (struct node *) malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=head;
    // printf("Before insertion\n");
    // display(head);
    // head=insert_at_first(head,4);
    // printf("After insertion\n");
    // display(head);
    // insert_at_last(head,5);
    // printf("After insertion\n");
    display(head);
    insert_in_between(head,6,1);
    printf("After insertion\n");
    display(head);
    return 0;

}