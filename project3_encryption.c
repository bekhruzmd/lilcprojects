/*
The program encrypts numbers by replacing digits with their positions in an encryption key.
It also reads a number digit by digit and maps each digit to its index in a 10-element encryption array.
*/

#include <stdio.h>

// this one replaces digits with their positions in the encryption array
void encrypt(int digits[], int encrypted[], int n, int encryption_array[]) {
    for (int i = 0; i < n; i++) { // for each digit in input
        int d = digits[i];
        // this is to search encryption array for the digit
        for (int j = 0; j < 10; j++) {
            if (encryption_array[j] == d) {
                encrypted[i] = j; // here we store index as encrypted value
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of digits:");
    scanf("%d", &n);
    
    // this reads number digit-by-digit using %1d format specifier
    int digits[n];
    printf("Enter the number:");
    for (int i = 0; i < n; i++) {
        scanf("%1d", &digits[i]); // this reads single digit
    }
    
    // this reads encryption key 
    //10-digit permutation
    int encryption_array[10];
    printf("Enter the encryption array: ");
    for (int i = 0; i < 10; i++) scanf("%d", &encryption_array[i]);
    
    // this encrypts and prints the result
    int encrypted[n];
    encrypt(digits, encrypted, n, encryption_array);
    
    for (int i = 0; i < n; i++) printf("%d", encrypted[i]);
    printf("\n");
    
    return 0;
}