/*
Description: The program reads a grocery list from a file and removes any duplicate items while preserving the original order. 
It then writes the unique items to a new output file, with each item on a separate line.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// big enough for the assignment
#define MAX_ITEMS 1000
#define MAX_LEN 101 // need +1 for null

// gets rid of that pesky newline
// takes a string and if there's a newline at the end, replaces it with a null terminator
// basically makes "apple\n" into "apple" so we can compare strings properly
void trim_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// check if we've seen this item before
// looks through all items we've stored so far and compares with the current one
// returns 1 if found (duplicate), 0 if not found (unique)
int item_exists(char list[][MAX_LEN], char *item, int count) {
    for (int i = 0; i < count; i++) {
        // strcmp returns 0 when strings match, so we found a dupe
        if (strcmp(list[i], item) == 0)
            return 1; // yep, it's a duplicate
    }
    return 0; // nope, this is new
}

int main(int argc, char *argv[]) {
    char grocery_list[MAX_ITEMS][MAX_LEN];  // 2D array to store our unique items
    char current_item[MAX_LEN];             // buffer for reading each line
    int unique_count = 0;                   // keeps track of how many unique items we have
    FILE *in_file, *out_file;
    
    // need exactly 2 args
    // program name is argv[0], input file is argv[1], output file is argv[2]
    if (argc != 3) {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    
    // open the input
    // fopen returns NULL if it can't open the file
    in_file = fopen(argv[1], "r");
    if (!in_file) {
        printf("Couldn't open input file %s\n", argv[1]);
        return 1;
    }
    
    // grab the items one at a time
    // fgets reads until newline or MAX_LEN-1 chars, and adds null terminator
    // it returns NULL when EOF or error happens
    while (fgets(current_item, MAX_LEN, in_file) && unique_count < MAX_ITEMS) {
        // strip newline
        trim_newline(current_item);
        
        // skip blanks - don't add empty lines to our list
        if (strlen(current_item) == 0)
            continue;
            
        // no dupes allowed - only add if we haven't seen this item before
        // this keeps the FIRST occurrence of each item, not later ones
        if (!item_exists(grocery_list, current_item, unique_count)) {
            // copy this item to our list of unique items
            strcpy(grocery_list[unique_count], current_item);
            unique_count++;  // increment our counter of unique items
        }
    }
    
    fclose(in_file);  // always close files when done with them
    
    // write out the results
    out_file = fopen(argv[2], "w");  // "w" mode creates new file or truncates existing one
    if (!out_file) {
        printf("Couldn't create output file %s\n", argv[2]);
        return 1;
    }
    
    // dump the list - write each unique item with a newline after it
    for (int i = 0; i < unique_count; i++) {
        fprintf(out_file, "%s\n", grocery_list[i]);  // fprintf writes formatted output to a file
    }
    
    fclose(out_file);  // close the output file when done
    return 0;  // return 0 means success in C
}