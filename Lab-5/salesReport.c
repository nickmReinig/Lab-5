/*This program was made by Nick Reinig on 10/15/2023
the purpose of this program is to print various pieces of information about a company's sales*/
#include <stdio.h>

int main (){
    /*The sales numbers and month names are hardcoded in*/
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char *months[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December" };
    /*a title is printed as per project requirements*/
    printf("Monthly sales report for 2022 \n");
    /*the sales for each month are printed using a for loop*/
    printf("Month \t sales \n");
    /*we will create an average variable here for use later, its calculation is very simple*/
    float average = 0;
    for (int i = 0; i < 12; i++){
        average = average + sales[i];
        printf("%s", months[i]);
        printf("\t $%f", sales[i]);
        printf("\n");
    }
    average = average/12;

    /*The sales summary is done*/
    printf("Sales summary: \n");
    /*the index value is used to reference to the index of the lowest or highest value*/
    int index = 0;
    for (int i = 0; i < 12; i++){
        /*If the value is less than that at the current index, it should become the new index*/
        if (sales[i] < sales[index]){
            index = i;
        }
    }
    /*The information is printed*/
    printf("Minimum: $%f", sales[index]);
    printf("\t (%s)\n", months[index]);

    /*for maximum we can run almost the exact same code and even reuse index*/
        for (int i = 0; i < 12; i++){
        /*If the value is less than that at the current index, it should become the new index*/
        if (sales[i] > sales[index]){
            index = i;
        }
    }
    /*The information is printed*/
    printf("Maximum: $%f", sales[index]);
    printf("\t (%s)\n", months[index]);
    /*print the average*/
    printf("Average: $%f \n", average);

    /*Now the logic for the six month moving average*/
    printf("Six month moving average: \n");
    /*a couple nested for loops will be used
    the first for loop will go from 0-5 and marks the first month of the average
    then the second for loop will reference the value from this loop
    and count up six months from there
    calculating and displaying the average for each one*/
    for (int i = 0; i <= 6; i++){
        float sixAverage = 0;
        for (int u = i; u <= i+6; u++){
            sixAverage = sixAverage + sales[u];
        }
        sixAverage = sixAverage/6;
        printf("%s - %s \t %f \n", months[i], months[i+5], sixAverage);
    }

    /*finally a bubble sort will be used to sort the parallel arrays
    in order to display them highest to lowest
    because we cant use a bool, 0 is used for false and 1 for true*/
    int ordered = 0;
    while (ordered == 0){
        ordered = 1;
        for (int i = 0; i < 11; i++){
            if (sales[i] < sales[i+1]){
                ordered = 0;
                /*both the sales value and the month value must be swapped*/
                float holdSale = sales[i];
                sales[i] = sales[i+1];
                sales[i+1] = holdSale;
                char *holdMonth = months[i];
                months[i] = months[i+1];
                months[i+1] = holdMonth;
            }
        }
    }

    /*The organized arrays can be printed*/
    printf("Sales report (highest to lowest) \n");
    for (int i = 0; i < 12; i++){
        printf("%s", months[i]);
        printf("\t $%f", sales[i]);
        printf("\n");
    }

}   