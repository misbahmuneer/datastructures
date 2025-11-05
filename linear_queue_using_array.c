#include <stdio.h>
# define N 5
int queue[N];
int front=-1;
int rear =-1;


int empty(int *front,int *rear){
    if(*front==-1 && *rear==-1)
    return 1;
    else
    return 0;
  }
  int full(int *rear){
    if(*rear==N-1)
        return 1;
    else
        return 0;

    }
  
  void enque(int *front,int *rear,int arr[]){
    int n;
      if(full(rear)){
        printf("insertion not possible, queue is full\n");
      }
      else{
        if(*front==-1 && *rear==-1){
            *front+=1;
            *rear+=1;
            printf("enter the data you want to enter\n");
            scanf("%d",&n);
             arr[*front]=n;
              printf("%d inserted successfully\n", n);
        }
        else{
            *rear+=1;
            printf("enter the data you want to enter\n");
            scanf("%d",&n);
             arr[*rear]=n;
              printf("%d inserted successfully\n", n);
        }
      }
  }
  void deque(int *front,int *rear,int arr[]){
    if(empty(front,rear)){
        printf("deletion not possible because the queue is already empty\n");
    }
    else{
        if(*front==*rear){
            printf("element dequed is %d\n" ,arr[*front]);
            *front=-1;
            *rear=-1;
        }
        else{
            printf("element dequed is %d\n" ,arr[*front]);
            *front+=1;
        }
    }
  }
int main(){
     int choice;
     int cont=1;
     do{
     printf("enter \n1:to enter element in que\n 2: to remove element from que \n 3:to exit\n ");
     scanf("%d",&choice);
     switch(choice){
        case 1:
          enque(&front,&rear,queue);
          break;
          case 2:
          deque(&front,&rear,queue);
          break;
          case 3:
          cont=0;
          break;
          default:
          printf("invalid input\n");
     }
      }while(cont==1);
    return 0;
}
