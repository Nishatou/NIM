
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool Nim();

int main()
{
    int pile;
    bool whoWin; //user win return true, otherwise false
    int scoreUser = 0;
    int scoreComp = 0;
    int turn = 0;

    while (turn != 3)
    { //keep running for 3 games one game for each pile.
        printf("Please select the pile (1, 2, 3) :  ");
        scanf("%d", &pile);
        printf("user select pile %d\n", pile);

        switch (pile)
        {
        case 1:
            turn++;
            whoWin = Nim();
            //if "whoWin" is true ->scoreUser+1, false-> scoreComp +1
            //2printf("whowin : %d \n", whoWin);
            if (whoWin)
            {
                //printf("aa1");
                scoreUser++;
            }
            else
            {
                //printf("false1 \n");
                scoreComp++;
            }
            break;

        case 2:
            turn++;
            whoWin = Nim();
            //printf("whowin : %d \n", whoWin);
            if (whoWin)
            {
                //printf("aa2");
                scoreUser++;
            }
            else
            {
                // printf("false2 \n");
                scoreComp++;
            }
            break;

        case 3:
            turn++;
            whoWin = Nim();
            //printf("whowin : %d \n", whoWin);
            //printf("%d", whoWin);
            if (whoWin)
            {
                //printf("aa3");
                scoreUser++;
            }
            else
            {
                //printf("false3 \n");
                scoreComp++;
            }
            break;

        default:
            printf("Sorry input invalid. ");
            break;
        }
    }

    //determine the winner which has most scores
    if (scoreComp > scoreUser)
    {
        printf("Computer is the winner\n");
    }
    else
        printf("User is the winner \n");
}

//Nim function is the heart of program to play Nim
//it will return true ->user wins, and false otherwise
bool Nim()
{
    bool play;
    //number of input marbles
    int count;
    //the largest limit input
    int max;
    //the end of the game
    int min = 1;

    int userInput;

    //the remainder after taking out by user and computer
    int remainder;
    int computerInput;
    int Once = 1;
    int win;

    //prompt user to input number of marbles
    printf("Please input number between 10 to 100 : \n");
    //user prompt to count
    scanf("%d", &count);

    //check if user input between 10 and 100
    if ((count >= 10) && (count <= 100))
    {
        //keep runing when the remainder is not 1
        while (count != 1)
        {
            //inform how many marbles in the piles
            printf("They are  %d  marbles in the pile. \n", count);
            printf("\n");

            //determine the lastgest that user can take : max = count/2 , min = 1
            max = count / 2;

            //prompt user to input
            printf("Please input a value between 1 and the %d : \n", max);
            //user input
            scanf("%d", &userInput);
            printf("userInput %d \n", userInput);
            printf("\n");

            //check if the userInput in the range (1 to max)
            if ((userInput >= 1) && (userInput <= max))
            {
                ////AFTER the each turn whose turn remainder equal to 1 is the "lose"
                //user turns
                //subtract the userInput from the pile (count)
                count = count - userInput;
                printf("The remainder is %d \n", count);
                printf("\n");

                if (count != 1)
                //if the remainder is not equal to 0 is mean a computer's turn.
                {
                    max = count / 2; // the new max = the left of pile /2
                    srand(time(0));
                    //computer turns
                    for (int i = 0; i < Once; i++)
                    {
                        //random value for computer to input range (max = count/2, min =1)
                        computerInput = (rand() % (max - min + 1)) + min;
                        printf("ComputerInput : %d \n", computerInput);
                        printf("\n");
                    }
                    //subtract from the left over of count
                    count = count - computerInput;
                    printf("The remainder is %d \n", count);

                    if (count == 1)
                    //after computer turns and remainder =1 -> user lose because the next turn will be user's turn
                    {

                        printf("You are lose this game \n");
                        printf("----------------------------------------\n");
                        play = false;
                    }
                }
                else if (count == 1)
                //after user's turn, the remainder =1 -> computer lose because the next turn will be computer's turn
                {
                    printf("Yeah, you win this game \n");
                    printf("----------------------------------------\n");
                    play = true;
                }
            }
            else
                printf("input is not valid. Try agian1. \n");

        } //end of while loop when count ==1
    }
    else
        printf("input is not valid. Try agian2.\n");

    return play;
}
