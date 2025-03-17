/*
This program converts a phone number containing letters into its numeric equivalent using the standard telephone keypad mapping. 
It processes command-line arguments using pointer arithmetic to convert each letter to its corresponding digit while preserving non-alphabetic characters.
*/

#include <stdio.h>
#include <ctype.h>

/* converts letters in a phone number to their corresponding digits
   stores result in output string */
void convert(char *input, char *output) {
    /* process each character using pointer arithmetic */
    while (*input != '\0') {
        if (isalpha(*input)) {
            char upper_char = toupper(*input);
            
            if (upper_char >= 'A' && upper_char <= 'C')
                *output = '2';
            else if (upper_char >= 'D' && upper_char <= 'F')
                *output = '3';
            else if (upper_char >= 'G' && upper_char <= 'I')
                *output = '4';
            else if (upper_char >= 'J' && upper_char <= 'L')
                *output = '5';
            else if (upper_char >= 'M' && upper_char <= 'O')
                *output = '6';
            else if (upper_char >= 'P' && upper_char <= 'S')
                *output = '7';
            else if (upper_char >= 'T' && upper_char <= 'V')
                *output = '8';
            else /* W, X, Y, Z */
                *output = '9';
        } else {
            /* keep digits and other characters as is */
            *output = *input;
        }
        
        input++;
        output++;
    }
    
    /* add null terminator */
    *output = '\0';
}

int main(int argc, char *argv[]) {
    /* check if correct number of arguments provided */
    if (argc != 2) {
        printf("Invalid number of arguments\n");
        return 1;
    }
    
    char result[100]; /* buffer for converted phone number */
    
    /* convert the phone number */
    convert(argv[1], result);
    
    /* display result */
    printf("%s\n", result);
    
    return 0;
}