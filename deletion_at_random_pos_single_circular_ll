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
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp=head;
do{
    printf(" %d\n",temp->data);
    temp=temp->next;
}while(temp!=head);
}
void freeList(struct node* head) {
    if (head == NULL) return;
    struct node* temp=head,* newnode=NULL;
   do{
        newnode=temp->next;
        free(temp);
        temp=newnode;
    }while (temp!= head);
}

struct node* delete_at_random(struct node* head,int n){
    struct node *prev,*temp;
    if(n==1 && head->next==head){
        free(head);
        return NULL;
    }
    else if(n==1 && head->next!=head){
        prev=head;
        head=head->next;
        temp=head;
        while(temp->next!=prev){
            temp=temp->next;
        }
        temp->next=head;
        free(prev);
     return head;
    }
    else{
        temp=head;
        for(int i=1;i<n;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        return head;
    }
    
}

int main(){
    int n;
    printf("How many nodes do you want? ");
    scanf("%d", &n);
    struct node* head = createlist(n);
    display_linked_list(head);
    int position;
    printf("enter the position where you want to delete\n");
    scanf("%d",&position);
    if(position>n){
        printf("not possible");
    }
    else{
    head=delete_at_random(head,position);
    display_linked_list(head);
    }
    freeList(head);
    return 0;
}
