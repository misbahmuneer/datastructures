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
 void delete_random(struct node* head,int element){
    struct node* temp=head,*prevnode=NULL,*next_node;
    while(temp->data!=element){
        prevnode=temp;
        temp=temp->next;
        if((temp->next==NULL&&temp->data!=element) || (temp->next==NULL&&temp->data==element))
        printf("not possible\n");
    }
    next_node=temp->next;
    prevnode->next=next_node;
    next_node->prev=prevnode;
    free(temp);
 }
int main(){
    int n;
    printf("enter the number of nodes you want to insert");
    scanf("%d",&n);
    struct node* head=create_list(n);
    display(head);
   int element;
   printf("enter the element after you want to delete\n");
   scanf("%d",&element);
   delete_random(head,element);
   display(head);
    freeList(head);
    return 0;
}
