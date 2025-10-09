
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
 struct node* insert_random(struct node* head,int element){
    struct node * temp=head,*prev_node=NULL;
    struct node* newnode;
    int n;
    int count=1;
    while(temp->data!=element){
         if(temp->data!=element&&temp->next==NULL){
            printf("given element not found in the list\n");
            return NULL;
        }
        prev_node=temp;
        temp=temp->next;
        count++;
    }
    if(count==1){
    printf("enter the value you want to insert in new node");
    scanf("%d",&n);
    head=create_node(n);
    head->prev=NULL;
    head->next=temp;
    temp->prev=head;
    return head;
    }
    else{
     printf("enter the value you want to insert in new node");
    scanf("%d",&n);
    newnode=create_node(n);
    newnode->next=prev_node->next;
    prev_node->next=newnode;
    newnode->prev=prev_node;
    temp->prev=newnode;   
    return head;
 }
}


int main(){
    int n;
    printf("enter the number of nodes you want to insert");
    scanf("%d",&n);
    struct node* head=create_list(n);
    display(head);
    int element;
    printf("enter the element before which you want to insert new node");
    scanf("%d",&element);
    head=insert_random(head,element);
    display(head);
    freeList(head);
    return 0;
}
