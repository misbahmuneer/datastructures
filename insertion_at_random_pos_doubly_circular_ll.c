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
struct node* insert_random(struct node* head,int pos,int size){
    int n;
    printf("enter the value you want to insert");
    scanf("%d",&n);
    struct node* newnode=create_node(n);
    struct node* last,*temp=head,*prevnode;
    if(newnode==NULL){
    printf("list is fuill\n");
    return head;
    }
    else{
        if(pos==1 && head==NULL){
            head=newnode;
            head->prev=newnode;
            head->next=newnode;
            return head;
        }
        else if(pos==1 && head!=NULL){
         newnode->next=head;
       newnode->prev=head->prev;
       head=newnode;
       head->next->prev = head;
       last=head->prev;
       last->next=head;
       return head;
        }
        else if(pos==size+1){
             while(temp->next!=head){
        temp=temp->next;
       }
       temp->next=newnode;
       newnode->prev=temp;
       newnode->next=head;
       head->prev=newnode;
       return head;
    }
    else{
        for(int i=1;i<pos;i++){
          prevnode=temp;
          temp=temp->next;
        }
        prevnode->next=newnode;
         newnode->prev=prevnode;
         newnode->next=temp;
         temp->prev=newnode;
         return head;
    }
        }
        
    }




int main(){
    int n;
    printf("enter the number of nodes you want to insert");
    scanf("%d",&n);
    struct node* head=create_list(n);
    display(head);
    int pos;
    printf("enter the position at which you want to enter\n");
    scanf("%d",&pos);
    if(pos<=n+1){
        head=insert_random(head,pos,n);
       display(head);
    }
    else{
        printf("insertion at given position is not possible\n");
    }
    
    freeList(head);
    return 0;
}
