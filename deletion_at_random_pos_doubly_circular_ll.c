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
     newnode->prev=NULL;
     return newnode;
}
struct node* create_list(int n){
    if (n <= 0) return NULL;
    struct node* head=NULL,*temp=NULL,*newnode;
    for(int i=0;i<n;i++){
        int data;
        printf("enter the value you want to enter in node");
        scanf("%d",&data);
        newnode=create_node(data);
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp->next=head;
    head->prev=temp;
    return head;
}
void display(struct node* head){
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    struct node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
void freeList(struct node* head) {
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    struct node* temp=head,*nextnode;
   do{
    nextnode=temp->next;
    free(temp);
    temp=nextnode;
   }while(temp!=head);
   head = NULL;
}
struct node* delete_random(struct node* head,int pos,int size){
    struct node* prevhead=head,*last,*temp=head,*prevnode,*nextnode;
    if(head==NULL){
        printf("the list is empty\n");
        return NULL;
    }
    else if(pos==1 && head->next==head){
        free(head);
        return NULL;
    }
    else if(pos==1 && head->next!=head){
     head=head->next;
    head->prev=prevhead->prev;
    last=prevhead->prev;
    last->next=head;
    free(prevhead);
    return head;
 }
 else if(pos==size){
     while(temp->next!=head){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=head;
    head->prev=prevnode;
    free(temp);
    return head;
 }
 else{
    for(int i=1;i<pos;i++){
        prevnode=temp;
        temp=temp->next;
    }
    nextnode=temp->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
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
    int pos;
    printf("enter the position at which you want to delete the node\n");
    scanf("%d",&pos);
    if(pos<=n){
        head=delete_random(head,pos,n);
       display(head);
    }
    else{
        printf("deletion at given position is not possible\n");
    }
    
    freeList(head);
    return 0;
}
