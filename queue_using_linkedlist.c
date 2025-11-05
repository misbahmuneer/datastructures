#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enque(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("insertion not possible\n");
    }
    else{
        newnode->next=NULL;
        newnode->data=n;
        if(front==NULL && rear==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=rear->next;
        }
    }
}
void freelist(){
    struct node* temp=front;
    while (front!=NULL)
    {
     temp=front;
     front=front->next;
     free(temp);
    }
    
}
void deque(){
    if(front==NULL && rear==NULL){
        printf("deletion not possible bcz the list is already empty\n");
    }
    else{
        if(front==rear){
            free(front);
            front=NULL;
            rear=NULL;
        }
        else{
            struct node*temp=front;
            front=front->next;
            free(temp);
        }
    }
}

int main(){
     int choice;
     int cont=1;
     int n;
     do{
     printf("enter \n1:to enter element in queue\n 2: to remove element from queue \n 3:to exit\n ");
     scanf("%d",&choice);
     switch(choice){
        case 1:
        printf("enter the elemernt you want to enter\n");
        scanf("%d",&n);
          enque(n);
          break;
          case 2:
          deque();
          break;
          case 3:
          cont=0;
          break;
          default:
          printf("invalid input\n");
     }
      }while(cont==1);
      freelist();
    return 0;
}
