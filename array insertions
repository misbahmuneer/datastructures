#include <stdio.h>
#define SIZE 100
int arr[SIZE]; 
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
// Function to add element at the beginning
void add_beginning(int value) {
int i;
for(i = n; i > 0; i--) {
arr[i] = arr[i - 1];  // Shift elements to the right
    }
arr[0] = value;
 n++;
}
// Function to add element at the end
void add_end(int value) {
arr[n] = value;
n++;
}
// Main function
int main() {
    create();
    display();
int val1, val2;
printf("Enter element to add at the beginning: ");
scanf("%d", &val1);
add_beginning(val1);
display();
printf("Enter element to add at the end: ");
scanf("%d", &val2);
add_end(val2);
display();
return 0;
}
