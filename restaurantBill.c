// insert libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// main
// tax and tip (as percentages) accepted from command line
int main( int argc, char *argv[] ) {
    
    srand(time(NULL));
    double meals[4] = {9.95, 4.55, 13.25, 22.35};
    double mealPrice = meals[(rand() % 4)]; //generates random meal number 0,1,2,3

    //converting command line arguments to decimals

    double tax_decimal = 0;
    double tip_decimal = 0;
    if(argc == 3) {
        sscanf(argv[1], "%lf", &tax_decimal);
        sscanf(argv[2], "%lf", &tip_decimal);
        tax_decimal = tax_decimal/100.0;
        tip_decimal = tip_decimal/100.0;
    }

    double taxAmount = mealPrice * tax_decimal;
    double tipAmount = mealPrice * tip_decimal;
    double totalBill = mealPrice + taxAmount + tipAmount;
    printf("Meal cost:  $%0.2f\n", mealPrice);
    printf("Tax amount: $%0.2f\n", taxAmount);
    printf("Tip amount: $%0.2f\n", tipAmount);
    printf("Total bill: $%0.2f\n", totalBill);

    return 0;
}

