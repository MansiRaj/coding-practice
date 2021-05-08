#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * delete_at_first(struct node *head){
    struct node *ptr=head;
    struct node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    head=head->next; 
    p->next=head;   
    free(ptr);
    return head;
}

void delete_at_last(struct node * head){
    struct node *ptr=head;
    while(ptr->next->next!=head){
        ptr=ptr->next;
    }
    struct node *p=ptr->next;
    ptr->next=head;
    free(p);
}

void delete_at_index(struct node *head,int index){
    int i=0;
    struct node *ptr=head;
    struct node *p;
    while(i!=index-1){
        p=ptr;
        ptr=ptr->next;
        i++;
    }
    p->next=ptr->next;
    free(ptr);
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
    struct node * forth= (struct node *) malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=forth;
    forth->data=4;
    forth->next=head;
    printf("before deletion\n");
    display(head);
    printf("after deletion\n");
    // head=delete_at_first(head);
    // display(head);
    // delete_at_last(head);
    // display(head);
    delete_at_index(head,2);
    display(head);
    return 0;
}