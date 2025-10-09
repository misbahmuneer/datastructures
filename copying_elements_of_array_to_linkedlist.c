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
void create_array(int arr[],int size){
    for(int i=0;i<size;i++){
     scanf("%d",&arr[i]);
    }
}
struct node* createlist(int size,int arr[]){
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int value;
    for(int i=0;i<size;i++){
      newnode=create_node(arr[i]);
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



int main(){
    int arr[20];
    int size;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the elements of an array");
    create_array(arr,size);
    struct node* head = createlist(size,arr);
    display_linked_list(head);
     freeList(head);
    return 0;
}
