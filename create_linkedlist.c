#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int main(){
    struct node* head = (struct node*) malloc(sizeof(struct node));
struct node* second = (struct node*) malloc(sizeof(struct node));
struct node* third = (struct node*) malloc (sizeof(struct node));
    head->data =5;
    head ->next =second;
    second->data = 10;
    second->next = third;
    third->data = 15;
    third->next = NULL;
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
