/*
This C program converts the last 7 letters in a phone number input 
to their corresponding telephone keypad digits (2-9). 
*/

#include <stdio.h>

int main() {
    char phone[1000];    
    char output[1000];   
    int length = 0;      
    int out_index = 0;   
    int c;

    // this reads input characters into phone buffer
    printf("Enter phone number: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        phone[length++] = c;
    }

    // this counts total letters in input
    int total_letters = 0;
    for (int i = 0; i < length; ++i) {
        char ch = phone[i];
        //checks if the character is a letter
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            total_letters++;
        }
    }

    int current_letter = 0; // this tracks which letter we're processing
    int i = 0;
    
    do {
        if (i >= length) break; //this stops after it has processed all input characters
        char ch = phone[i];
        
        // this checks if character is a letter
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            current_letter++;
            
            // this only converts last 7 letters
            if (current_letter > (total_letters - 7)) {
                // this converts lowercase to uppercase
                if (ch >= 'a' && ch <= 'z') {
                    ch -= 32;
                }
                
                // this is a map letter to digit via switch
                switch (ch) {
                    case 'A': case 'B': case 'C': 
                        output[out_index++] = '2'; break;
                    case 'D': case 'E': case 'F': 
                        output[out_index++] = '3'; break;
                    case 'G': case 'H': case 'I': 
                        output[out_index++] = '4'; break;
                    case 'J': case 'K': case 'L': 
                        output[out_index++] = '5'; break;
                    case 'M': case 'N': case 'O': 
                        output[out_index++] = '6'; break;
                    case 'P': case 'Q': case 'R': case 'S': 
                        output[out_index++] = '7'; break;
                    case 'T': case 'U': case 'V': 
                        output[out_index++] = '8'; break;
                    case 'W': case 'X': case 'Y': case 'Z': 
                        output[out_index++] = '9'; break;
                }
            } else {
                output[out_index++] = ch; // non-converted letter
            }
        } else {
            output[out_index++] = ch; // non-letter character
        }
        i++; //move to the next character in input buffer yurrrr
    } while (i < length); //continue until all characters are processed

    // this null-terminates and prints final result
    output[out_index] = '\0';
    printf("%s\n", output);

    return 0;
}