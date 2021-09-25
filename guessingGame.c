// insert libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// main
int main() {
    int user_menu_input, menu_flag, guess;
    unsigned int max_number = 10;
    char user_guess[20] = "";
    menu_flag = 1;
    while (menu_flag == 1) {
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%d", &user_menu_input);

        //switch statements for the following cases
        switch(user_menu_input) {

            case 1: //press 1 to play a game
                srand(time(NULL));
                int answer = (1 + (rand() % max_number));
                int guess_flag = 1;
                while (guess_flag == 1) {
                    printf("Enter a number: "); //prompt user to enter number to play game
                    scanf(" %s", &user_guess);
                    //making sure to check for q input to return to menu
                    if (strcmp(user_guess, "q") == 0) {
                        guess_flag = 0;
                        break;
                    }
                    else if (atoi(user_guess) == answer) {
                        guess_flag = 0;
                        printf("Congratulations! That was the correct answer.\n");
                        break;
                    }
                    else if (atoi(user_guess) < answer) {
                        printf("Your answer was too low. Guess again.\n");
                    }
                    else if (atoi(user_guess) > answer) {
                        printf("Your answer was too high. Guess again.\n");
                    } 
                }
                break;

            case 2: //press 2 to change the max number
                printf("Enter max value (must be positive and cannot exceed 4,294,967,295): "); //cannot be bigger than the 32 bit unsigned int max value
                int temp;
                scanf("%d", &temp);
                if (temp > 0 && temp <= 4,294,967,295) {
                    max_number = temp;
                }
                else {
                    printf("Not a valid max number.");
                }
                break;

            case 3: //press 3 to quit
                printf("Thanks for playing!");
                menu_flag = 0;
                break;   
        }
    }
    return 0;
}