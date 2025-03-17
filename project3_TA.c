/*
The program finds the unassigned TA from a list of assigned TAs. 
It also  reads total TAs and TA numbers, tracks presence using an array. 
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of TAs:");
    scanf("%d", &n);
    
    // this is an array to store assigned TAs 
    int assigned[n - 1];
    printf("Enter TAs already assigned:");
    //n-1 entries since one is missing
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &assigned[i]);
    }
    
    // this one tracka presence of TAs 
    int present[n + 1]; 
    for (int i = 0; i <= n; i++) present[i] = 0; // initialized to 0 
    
    // this loop marks assigned TAs as present
    for (int i = 0; i < n - 1; i++) present[assigned[i]] = 1;
    
    // this one finds and prints the first missing TA
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            printf("TA has not been assigned: %d\n", i);
            break;
        }
    }
    
    return 0;
}