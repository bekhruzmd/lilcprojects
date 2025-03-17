/*
Description: This program calculates dumpster rental costs based on selection and rental days.
It validates inputs and displays the total charge in dollars.
*/

#include <stdio.h>

int main(void) {
    int selection, days;
    int first_day_maney, daily_maney, weekly_max, charge;
    //this prints what the user needs to do 
    printf("Please select from four types of dumpsters: 1, 2, 3, and 4\n");
    printf("Enter dumpster selection:");
    scanf("%d", &selection);

    // this is validating the selection 
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;
    }

    printf("Enter days:");
    scanf("%d", &days);

    // this validates the days yurrrr
    if (days < 0) {
        printf("Invalid days.\n");
        return 1;
    }

    // this initializes the charges based on selection
    switch (selection) {
        case 1: // maney for 10-yard dumpster
            first_day_maney = 120;
            daily_maney = 80;
            weekly_max = 380;
            break;
        case 2: // maney for 20-yard dumpster
            first_day_maney = 150;
            daily_maney = 100;
            weekly_max = 420;
            break;
        case 3: // maney for 30-yard dumpster
            first_day_maney = 180;
            daily_maney = 120;
            weekly_max = 520;
            break;
        case 4: // maney for 40-yard dumpster
            first_day_maney = 200;
            daily_maney = 140;
            weekly_max = 600;
            break;
    }

    // this is the calculations for the dumpster thingy
    if (days == 1) {
        charge = first_day_maney;
    } else {
        int weeks = days / 7;
        int remaining_days = days % 7;

        charge = weeks * weekly_max;

        if (remaining_days == 1) {
            charge += first_day_maney;
        } else if (remaining_days > 1) {
            int temp_charge = first_day_maney + (remaining_days - 1) * daily_maney;
            charge += (temp_charge > weekly_max ? weekly_max : temp_charge);
        }
    }

    // output the results of the dumpster stuff 
    printf("Charge($):%d\n", charge);

    return 0;
}
