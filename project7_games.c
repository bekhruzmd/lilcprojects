/*
This program reads video game data from a CSV file and lets users search for games by console type. 
It saves the matching results to a new CSV file for easy viewing.
*/

#include <stdio.h>
#include <string.h>

// max number of games we can handle
#define MAX_GAMES 1000
// max length for strings
#define MAX_STRING 101

// struct for game info
struct game {
    char title[MAX_STRING];
    char genre[MAX_STRING];
    int review_score;
    double used_price;
    char console[MAX_STRING];
    char rating[MAX_STRING];
};

// function prototypes
int read_line(char str[], int n);
int search(struct game list[], int n, struct game result[], char *search_console);

int main() {
    struct game games[MAX_GAMES];    // array for all games
    struct game result[MAX_GAMES];   // array for search results
    char filename[MAX_STRING];       // input file name
    char search_console[MAX_STRING]; // console to search for
    FILE *fp;                        // file pointer
    int count = 0;                   // number of games read
    int result_count;                // number of matches found

    // get filename from user
    printf("Enter file name: ");
    read_line(filename, MAX_STRING);

    // get console to search for
    printf("Enter the console for searching: ");
    read_line(search_console, MAX_STRING);

    // try to open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // read games from file until eof or max reached
    while (count < MAX_GAMES && 
           fscanf(fp, "%[^,], %[^,], %d, %lf, %[^,], %[^\n]\n", 
                  games[count].title, 
                  games[count].genre, 
                  &games[count].review_score, 
                  &games[count].used_price, 
                  games[count].console, 
                  games[count].rating) == 6) {
        count++;
    }

    fclose(fp);

    // do the search
    result_count = search(games, count, result, search_console);

    // create output file
    fp = fopen("result.csv", "w");
    if (fp == NULL) {
        printf("Error creating output file\n");
        return 1;
    }

    // write matches to output file
    for (int i = 0; i < result_count; i++) {
        fprintf(fp, "%s, %s, %d, %.2f, %s, %s\n",
                result[i].title,
                result[i].genre,
                result[i].review_score,
                result[i].used_price,
                result[i].console,
                result[i].rating);
    }

    fclose(fp);

    return 0;
}

// reads a line from stdin
int read_line(char str[], int n) {
    int ch, i = 0;

    // read chars until newline or eof
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n - 1) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';  // add null terminator
    return i;
}

// find games by console name
int search(struct game list[], int n, struct game result[], char *search_console) {
    int result_count = 0;

    // check each game
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].console, search_console) == 0) {
            // found a match, add to results
            result[result_count] = list[i];
            result_count++;
        }
    }

    return result_count;
}