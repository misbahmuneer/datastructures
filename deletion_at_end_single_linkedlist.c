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
    return head;
}
void display_linked_list(struct node* ptr){
while(ptr!=NULL){
    printf(" %d\n",ptr->data);
    ptr=ptr->next;
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
struct node* delete_end(struct node* head){
     if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
     if (head->next == NULL) {  // only one node
        free(head);
        return NULL;
    }
    struct node* temp=head;
    struct node* prev=NULL;
    while(temp->next!=NULL){
      prev=temp;
      temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return head;
}

int main(){
    int n;
    printf("How many nodes do you want? ");
    scanf("%d", &n);

    struct node* head = createlist(n);
    display_linked_list(head);
    head =delete_end(head);
    display_linked_list(head);
    freeList(head);
    return 0;
}
