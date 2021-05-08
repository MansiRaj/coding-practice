#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
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
    head->prev=ptr;
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
    ptr->prev=p;
    head->prev=ptr;

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
    p->next->prev=ptr;
    p->next=ptr;
    ptr->prev=p;
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

void display_rev(struct node *head){
    struct node *p=head->prev;
    printf("%d\n",p->data);
    p=p->prev;
    while(p!=head->prev){
        printf("%d\n",p->data);
        p=p->prev;
    }
}

int main(){
    struct node * head= (struct node *) malloc(sizeof(struct node));
    struct node * second= (struct node *) malloc(sizeof(struct node));
    struct node * third= (struct node *) malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    head->prev=third;
    second->data=2;
    second->next=third;
    second->prev=head;
    third->data=3;
    third->next=head;
    third->prev=second;
    printf("Before insertion\n");
    display(head);
    // head=insert_at_first(head,4);
    // printf("After insertion\n");
    // display(head);
    // insert_at_last(head,5);
    // printf("After insertion\n");
    // display(head);
    insert_in_between(head,6,1);
    printf("After insertion\n");
    display(head);
    printf("reverse list\n");
    display_rev(head);
    return 0;

}