/*
This is a program that assigns students to three different tiers based 
on how close their points are to predefined tier thresholds using pointer arithmetic.
*/

#include <stdio.h>
#include <stdlib.h> // for abs() function

//assigns students to tiers based on their points
void assign_tier(int *points, int *tier, int n);

//displays the students in each tier according to the required format
void display_tiers(int *tier, int n);

int main() {
    int n;
    
    // gets the number of students from the user
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    // creates arrays to store points and tier assignments
    int points[n];
    int tier[n];
    
    // gets the points for each student from the user
    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
    }
    
    // assigns students to tiers based on their points
    assign_tier(points, tier, n);
    
    // displays the tier assignments
    display_tiers(tier, n);
    
    return 0;
}

void assign_tier(int *points, int *tier, int n) {
    // sets up pointers to traverse the arrays
    int *point_ptr = points;
    int *tier_ptr = tier;
    
    // defines the tier thresholds
    int tier1 = 30, tier2 = 75, tier3 = 120;
    
    // assigns each student to the closest tier
    for (int i = 0; i < n; i++) {
        // calculates the distance from the student's points to each tier threshold
        int dist1 = abs(*point_ptr - tier1);
        int dist2 = abs(*point_ptr - tier2);
        int dist3 = abs(*point_ptr - tier3);
        
        // assigns the student to the tier with the minimum distance
        // if there's a tie, the lower tier takes precedence
        if (dist1 <= dist2 && dist1 <= dist3) {
            *tier_ptr = 1; 
        } else if (dist2 <= dist1 && dist2 <= dist3) {
            *tier_ptr = 2; 
        } else {
            *tier_ptr = 3;
        }
        
        point_ptr++;
        tier_ptr++;
    }
}

void display_tiers(int *tier, int n) {
    // Display tier 1
    printf("Tier 1: ");
    int found = 0;
    
    // First check if there are any students in tier 1
    for (int i = 0; i < n; i++) {
        if (tier[i] == 1) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("student");
        for (int i = 0; i < n; i++) {
            if (tier[i] == 1) {
                printf(" %d", i + 1);
            }
        }
    } else {
        printf("none");
    }
    printf("\n");
    
    // Display tier 2
    printf("Tier 2: ");
    found = 0;
    
    // First check if there are any students in tier 2
    for (int i = 0; i < n; i++) {
        if (tier[i] == 2) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("student");
        for (int i = 0; i < n; i++) {
            if (tier[i] == 2) {
                printf(" %d", i + 1);
            }
        }
    } else {
        printf("none");
    }
    printf("\n");
    
    // Display tier 3
    printf("Tier 3: ");
    found = 0;
    
    // First check if there are any students in tier 3
    for (int i = 0; i < n; i++) {
        if (tier[i] == 3) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("student");
        for (int i = 0; i < n; i++) {
            if (tier[i] == 3) {
                printf(" %d", i + 1);
            }
        }
    } else {
        printf("none");
    }
    printf("\n");
}