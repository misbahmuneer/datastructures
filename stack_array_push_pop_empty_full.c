#include <stdio.h>
# define N 5
int stack[N];
int top=-1;
int full(int Top){
    if(Top==N-1){
        printf("the stack is full");
        return 1;
    }
    else
    return 0;
}
int empty(int Top){
    if(Top==-1){
        printf("the stack is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int push(int Top,int arr[]){
    Top++;
    int n;
    printf("enter the data you want to enter\n");
    scanf("%d",&n);
    arr[Top]=n;
    return Top;
}
int pop(int Top,int arr[]){
   printf("element popped is %d",arr[Top]);
   Top--;
   return Top;
}

int main(){
    int choice=0;
    int exit=0;
    while(exit!=1){
    printf("to push an element press1,\nto pop ->2\n to exit->3\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
             if(full(top)!=1){
                top=push(top,stack);
             }
             break;
          case 2:
          if(empty(top)!=1){
            top=pop(top,stack);
          }
            break;
            case 3:
            exit=1;
            break;
            default:
            printf("invalid input\n");
            break;
    
}
    }
    return 0;
    }
