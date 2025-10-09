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
struct node* delete_random(struct node* head,int n,int post){
    struct node* temp=head,*prev_node=NULL,*next_node=NULL;
if(post==1){
     head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}
else if(post==n){
    while(temp->next!=NULL){
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=NULL;
    free(temp);
    return head;
}
else{
   for(int i=1;i<post;i++){
    prev_node=temp;
    temp=temp->next;
   }
   next_node=temp->next;
   prev_node->next=next_node;
   next_node->prev=prev_node;
   free(temp);
   return head;
}
}

int main(){
    int n;
    printf("enter the number of nodes you want to insert");
    scanf("%d",&n);
    struct node* head=create_list(n);
    display(head);
    int position;
    printf("enter the position at which you want to delete the node");
    scanf("%d",&position);
    if(position>n){
        printf("not possible");
    }
    else{
    head=delete_random(head,n,position);
    display(head);
    }
    freeList(head);
    return 0;
}
