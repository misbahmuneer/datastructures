#include <stdio.h>
int arr[100];  
int n;         
// Function to create the array
void create() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
// Function to display the array
void display() {
    int i;
    printf("Array elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function to replace element at kth position (0 based index)
void replace_at_k(int k, int value) {
    if(k < 0 || k >= n) {
        printf("Invalid position!\n");
        return;
    }
arr[k] = value;
}
// Main function
int main() {
    int k, value;
    create();
    display();
    printf("Enter position to replace: ");
    scanf("%d", &k);
    printf("Enter new value: ");
    scanf("%d", &value);
    replace_at_k(k, value);
    display();
return 0;
}
