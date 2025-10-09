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
struct node* concat(struct node* head1,struct node* head2){
    if (head1 == NULL) return head2; // if first list empty
    if (head2 == NULL) return head1; // if second list empty
    struct node* head=head1,*temp=head1;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=head2;
    return head;
}


int main(){
    int n1,n2;
    printf("How many nodes do you want in 1 linked list? ");
    scanf("%d", &n1);
    struct node* head1 = createlist(n1);
    printf("How many nodes do you want in 2 linked list? ");
    scanf("%d", &n2);
    struct node* head2 = createlist(n2);
    printf("the linked lists are\n");
    display_linked_list(head1);
    printf("\n");
    display_linked_list(head2);
     printf("\n");
    struct node* head=concat(head1,head2);
    display_linked_list(head);
     freeList(head);
    return 0;
}
