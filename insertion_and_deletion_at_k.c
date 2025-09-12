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
// Function to insert element at kth position (0 based index)
void insert_at_k(int value, int k) {
    if(k < 0 || k > n) {
        printf("Invalid position!\n");
        return;
    }
for(int i = n; i > k; i--) {
        arr[i] = arr[i - 1];  // Shift elements right
    }
arr[k] = value;
    n++;
}
// Function to delete element at kth position (0 based index)
void delete_at_k(int k) {
    if(k < 0 || k >= n) {
        printf("Invalid position!\n");
        return;
    }
for(int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements left
    }
    n--;
}
// Main function
int main() {
    int value, k;
    create();
    display();
// Insertion at k
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert at: ");
    scanf("%d", &k);
    insert_at_k(value, k);
    display();
// Deletion at k
    printf("Enter position to delete from: ");
    scanf("%d", &k);
    delete_at_k(k);
    display();
return 0;
}
