#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* create_node(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {    
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
    
}
struct node* push(struct node* top){
    int data;
    printf("enter the data you want to insert in newnode\n");
    scanf("%d",&data);
    struct node * newnode=create_node(data);
    if(newnode==NULL){
        printf("the stack is full\n");
    }
    else{
        newnode->next=top;
        top=newnode;
    }
    return top;
}
struct node* pop(struct node* top){
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("element popped is %d\n",top->data);
        struct node* temp=top;
        top=top->next;
        free(temp);
    }
    return top;
}
void freeList(struct node* top) {
    struct node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}
int main(){
    struct node* top=NULL;
    int choice;
    int exit=0;
    while(exit!=1){
        printf("to push press 1\n to pop press 2\n to exit press 3\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            top=push(top);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            exit=1;
            break;
            default:
            printf("invalid input\n");
            break;
        }
    }

    freeList(top);
    return 0;
}
