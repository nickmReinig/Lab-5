/*This program was made by Nick Reinig on 10/15/2023
The purpose of this program is to allow the user to see what combinations make certain nfl scores*/
#include <stdio.h>

int main (){
    /*User input, called target, is collected here*/
    int target;
    printf("Enter a number larger than one to see scoring options \n");
    printf("Enter a number 1 or lower to end the program \n");
    printf("Enter your number: ");
    scanf("%d", &target);
    /*the program will loop until the user exits it*/
    while (target > 1){
        /*By using four nested for loops we can solve this problem
        each loop represents a different scoring option
        and by using nested for loops we can test every combination in relatively few lines*/
        int score = 0;
        for (int safeties = 0; safeties*2 <= target; safeties++){
            for (int fieldGoals = 0; fieldGoals*3 <= target; fieldGoals++){
                for (int touchdowns = 0; touchdowns*6 <= target; touchdowns++){
                    for (int extraPoints = 0; extraPoints*7 <= target; extraPoints++){
                        for (int twoPoints = 0; twoPoints*8 <= target; twoPoints++){
                            score = safeties*2 + fieldGoals*3 + touchdowns*6 + extraPoints*7 + twoPoints*8;
                            if (score == target){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", twoPoints, extraPoints, touchdowns, fieldGoals, safeties);
                            }

                        }
                    }
                }
            }
        }

        /*target is collected again to either loop or exit*/
        printf("Enter your number: ");
        scanf("%d", &target);
    }

    return 0;
}

