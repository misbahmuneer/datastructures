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
// Function to delete the first element
void delete_beginning() {
if(n == 0) {
printf("Array is empty.cannot delete.\n");
        return;
    }
for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift left
    }
    n--; 
}
// Function to delete the last element
void delete_end() {
if(n == 0) {
printf("Array is empty. Cannot delete.\n");
        return;
    }
    n--; 
}
// Main function
int main() {
create();
display();
printf("Deleting first element...\n");
delete_beginning();
display();
printf("Deleting last element...\n");
delete_end();
display();
        return 0;
}

