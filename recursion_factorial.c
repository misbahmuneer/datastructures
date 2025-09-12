#include <stdio.h>
// Recursive factorial function with memoization and function call count
int f(int x, int memo[], int* count)
{
    (*count)++;  // Increment the function call counter
 // Base case
    if (x == 0 || x == 1)
        return 1;
    if (memo[x] != -1)
        return memo[x];
    memo[x] = x * f(x - 1, memo, count);
    return memo[x];
}
int main()
{
    int number;
    int count = 0;
    printf("Enter the number whose factorial you want to get: ");
    scanf("%d", &number);

    int memo[100];  // Memoization array
    for (int i = 0; i < 100; i++)
        memo[i] = -1;
    int result = f(number, memo, &count);
    printf("Factorial of %d is %d, and the function was called %d times.\n",
           number, result, count);

    return 0;
}
