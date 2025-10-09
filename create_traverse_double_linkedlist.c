#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* create(int n){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    if (head==NULL){
        printf("not possible");
        return NULL;
    }
    int data;
    printf("enter the data you want to insert in head node");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    head->next=NULL;
      struct node* temp=head;
      for(int i=2;i<=n;i++){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode==NULL){
        printf("not possible");
        return NULL;
    }
        printf("enter the data you want to insert in %d node",i);
        scanf("%d",&data);
        newnode->data=data;
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        temp->next=NULL;

         }
         return head;
}
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int n;
    printf("enter the number of nodes");
    scanf("%d",&n);
    struct node* head=create(n);
     display(head);
    freeList(head);
    return 0;
}
