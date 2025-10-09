#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node* prev;
};
struct node* create_node(int n){
     struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=n;
     newnode->next=NULL;
     return newnode;
}
struct node* create_list(int n){
    struct node* head=NULL,*temp=NULL,*newnode;
    for(int i=0;i<n;i++){
        int data;
        printf("enter the value you want to enter in node");
        scanf("%d",&data);
        newnode=create_node(data);
        if(head==NULL){
            head=newnode;
            head->prev=NULL;
            temp=head;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
            temp->next=NULL;
        }
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
 void insert_end(struct node* head){
    struct node * temp=head;
    struct node* newnode;
    int n;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("enter the value you want to insert in new node");
    scanf("%d",&n);
    newnode=create_node(n);
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
}


int main(){
    int n;
    printf("enter the number of nodes you want to insert");
    scanf("%d",&n);
    struct node* head=create_list(n);
    display(head);
    insert_end(head);
    display(head);
    freeList(head);
    return 0;
}
