/*
This program checks if a given input string consists of a word repeated twice in a row (like "blingbling").
It uses pointer arithmetic instead of array subscripting to compare the first half of the string with the second half to determine if they're identical.
*/


#include <stdio.h>
#include <string.h>

// read_line: reads a line of input into the string using pointer arithmetic
int read_line(char *str, int n) {
    int ch;
    char *p = str;  // pointer to current position in str
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (p - str < n)
            *p++ = ch;
    }
    *p = '\0';
    return p - str;
}

// is_doubled: returns 1 if input is some word written twice in a row, 0 otherwise
int is_doubled(char *input) {
    // get the length of the input using strlen
    int len = strlen(input);
    
    // if length is odd, it cannot be a doubled word
    if (len % 2 != 0)
        return 0;
    
    // set pointer for first half and second half of the input
    char *p = input;
    char *q = input + len / 2;
    
    // compare characters using pointer arithmetic
    while (*p != '\0' && *q != '\0') {
        if (*p != *q)
            return 0;
        p++;
        q++;
    }
    
    return 1;
}

int main() {
    char input[1001]; // allocate space for input (max 1000 characters + null)
    
    // prompt the user for input
    printf("Enter input: ");
    read_line(input, 1000);
    
    // check if the input is a doubled word and display result
    if (is_doubled(input))
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}
