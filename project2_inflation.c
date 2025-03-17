/*

This C program calculates an item's price for the next 5 years (2025–2029) assuming a fixed 3% annual inflation rate. 
*/
#include <stdio.h>

int main() {
    /*im using double for precision*/
    double price;
    printf("Enter the price of the item in 2024: ");
    scanf("%lf", &price);
    /*the loop runs 5 times, iterates one year from 2025 to 2029. with each iteration, the price increases by 3%*/
    for (int i = 0; i < 5; i++) {
        price *= 1.03;
        int year = 2025 + i;
        /*the output prints each year, formatted to 2 decimal places*/
        printf("The anticipated price in %d is %.2f\n", year, price); 
    }
    
    return 0;
}