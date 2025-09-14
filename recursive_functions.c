#include <stdio.h>
int f_x(int);
int g_x(int);
int f_x(int n) {
    printf("We are in f(x) for x = %d\t", n);
    if (n <= 0) {
        return 1;
    } else {
        return n * g_x(n - 1);
    }
}
int g_x(int n) {
    printf("We are in g(x) for x = %d\t", n);
    if (n <= 0) {
        return 2;
    } else {
        return n - f_x(n - 2);
    }
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
int result_f = f_x(n);  
int result_g = g_x(n);  
    printf("\n\nf(x) for x = %d is %d\n", n, result_f);
    printf("g(x) for x = %d is %d\n", n, result_g);
    return 0;
}
