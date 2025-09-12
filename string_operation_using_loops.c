#include <stdio.h>
// Function to find the length of the string
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
// Function to copy one string into another
void stringCopy(char str1[], char str2[]) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}
// Function to compare two strings
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; // Difference between mismatched characters
        }
        i++;
    }
    return str1[i] - str2[i]; 
}
// Function to concatenate two strings
void stringConcat(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') {
        i++; 
    }
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}
int main() {
    char str1[100] = "hello";
    char str2[] = "world";
    char str3[100]; 
    int len1 = stringLength(str1);
    printf("Length of str1: %d\n", len1);
    int len2 = stringLength(str2);
    printf("Length of str2: %d\n", len2);
    stringCopy(str3, str1);
    printf("str3 after copy: %s\n", str3);
    int cmp = stringCompare(str1, str2);
    if (cmp == 0) {
        printf("str1 and str2 are equal\n");
    } else if (cmp > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is less than str2\n");
    }
    stringConcat(str1, str2);
    printf("After concatenation, str1: %s\n", str1);
    return 0;
}
