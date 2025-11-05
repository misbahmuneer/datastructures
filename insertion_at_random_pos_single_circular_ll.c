#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create_node(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
    
}
struct node* createlist(int size){
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int value;
    for(int i=0;i<size;i++){
      printf("enter the value for %d node",i+1);
      scanf("%d",&value);
      newnode=create_node(value);
      if(head==NULL){
        head=newnode;
        temp=head;
      }
      else{
        temp->next=newnode;
        temp=newnode;
      }
    }
    temp->next=head;
    return head;
}
void display_linked_list(struct node* head){
    struct node* temp=head;
do{
    printf(" %d\n",temp->data);
    temp=temp->next;
}while(temp!=head);
}
void freeList(struct node* head) {
    struct node* temp=head,* newnode=NULL;
   do{
        newnode=temp->next;
        free(temp);
        temp=newnode;
    }while (temp!= head);
}
struct node* insert_random(struct node* head,int n){
    struct node* prev=head, *newnode;
    int val;
     printf("enter the value you want to insert in newnode");
    scanf("%d",&val);
    newnode=create_node(val);
    if(newnode==NULL){
        printf("insertin not possible");
        return head;
    }
    else{
   
    
    if(n==1 && head==NULL){
       newnode->next=newnode; 
       head=newnode;
    }
    else if(n==1 && head!=NULL){
    newnode->next=head;
     head=newnode;
     struct node* temp=prev;
     while(temp->next!=prev){
        temp=temp->next;
     }
     temp->next=head;
    }
    else {
        for(int i=1;i<n-1;i++){
            prev=prev->next;
        }
        newnode->next=prev->next;
        prev->next=newnode;
     
    }
}
     return head;
}

int main(){
    int n;
    printf("How many nodes do you want? ");
    scanf("%d", &n);

    struct node* head = createlist(n);
    display_linked_list(head);
    int pos;
    printf("enter the position at which you want to insert the node");
    scanf("%d",&pos);
    if(n<=n+1){
        head=insert_random(head,pos);
        display_linked_list(head);
    }
    else{
        printf("insertion at this position is not possible\n");
    }
    freeList(head);
    return 0;
}
