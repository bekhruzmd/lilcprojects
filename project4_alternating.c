/*
This is a program that checks if a user-entered sequence of numbers alternates 
between positive and negative values using pointer arithmetic.
*/

#include <stdio.h>


//it checks if a sequence is alternating (elements alternate between positive and negative)
int is_alternating_sequence(int *sequence, int n);

int main() {
    int n;
    
    // this gets the length of the sequence from the user
    printf("Enter length of the sequence: ");
    scanf("%d", &n);
    
    // this one creates an array to store the sequence
    int sequence[n];
    
    // this gets the numbers of the sequence from the user
    printf("Enter numbers of the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    
    // checks if the sequence is alternating and displays the result
    if (is_alternating_sequence(sequence, n)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

int is_alternating_sequence(int *sequence, int n) {
    // handles edge cases: empty sequences or single-element sequences are trivially alternating
    if (n <= 1) {
        return 1;
    }
    
    // first checks if the first two elements have the same sign (which would make it non-alternating)
    if ((*sequence > 0 && *(sequence + 1) > 0) || 
        (*sequence < 0 && *(sequence + 1) < 0)) {
        return 0; // same sign means not alternating
    }
    
    // this sets up pointers to check consecutive elements
    int *current = sequence;
    int *next = sequence + 1;
    
    // checks each pair of adjacent elements to ensure they have opposite signs
    for (int i = 1; i < n - 1; i++) {
        // if current and next elements have the same sign, it's not alternating
        if ((*current > 0 && *next > 0) || (*current < 0 && *next < 0)) {
            return 0;
        }
        // moves to the next pair of elements
        current++;
        next++;
    }
    
    return 1;
}