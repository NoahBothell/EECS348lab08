//name: noah bothell
//KUID: 3179068
//date created: 10/19/2025

//my program will return all possible *combinations* of plays that could result in a certain score
//to do that, I will loop through multiple solutions to create all possibilities
//The loop will take a given list of plays and the current score left to cover and will find all possible next plays
//In order to avoid repeating, I will create a hirearchy of plays and make the program only able to go down the hirearchy and not up
//hirearchy: TD(6), Field Goal(3), safety(2), TD+2 conversion(8), TD+1 conversion(7) points are in parenthises.
#include <stdio.h>
#include <math.h>

void printCombo(int arr[]);
int identicalArray(int arr[5], int newArr[5]);
void TD(int score);
void fieldGoal(int score, int arr[]);
void Safety(int score, int arr[]);
void TouchDown2(int score, int arr[]);
void TouchDown1(int score, int arr[]);

int main()
{
    int NFLScore = 0;
    //keeps running the program until the user inputs 1
    while (NFLScore != 1){
        printf("Please enter the score of the game (or 1 to end):\n");
        scanf("%d", &NFLScore);
        //makes sure the digit entered is 0 or up as a negative score is not possible
        while (NFLScore <= 0){
            printf("Invalid input, please enter a positive integer:\n");
            scanf("%d", &NFLScore);
        }
        //so long as the score is not equal to 1 (the exit value) 
        if (NFLScore != 1){
            TD(NFLScore);
        }
    }
    return 0;
}


//prints out the play array
void printCombo(int arr[]){
    printf("\nTouch Downs: %i", arr[0]);
    printf(" | Field Goals: %i", arr[1]);
    printf(" | Safeties: %i", arr[2]);
    printf(" | Touch down +2 conversions: %i", arr[3]);
    printf(" | Touch down +1 conversions: %i\n", arr[4]);
}

//makes newArr's contents identical to arr
int identicalArray(int arr[5], int newArr[5]){
    int i;
    for (i = 0; i < 5; i++){
        newArr[i] = arr[i];
    }
    return 1;
}

// loops through all possible amounts of touchdowns for the score
// it then hands that and the leftover score to the fieldGoal function
void TD(int score){
    int totalIterations = floor(score/6);
    int arr[5];
    int ScoreValue = 0;
    int i;
    int newArr[5];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    for (i = 0; i <= totalIterations; i++){
        ScoreValue = 6*i;
        arr[0] = i;
        identicalArray(arr, newArr);
        fieldGoal(score - ScoreValue, newArr);
    }
    return;
}

//loops through all possible values for fieldgoals and hands it off to safety each loop
void fieldGoal(int score, int arr[]){
    int totalIterations = (score/3) + 1;
    int ScoreValue = 0;
    int i;
    int newArr[5];
    identicalArray(arr, newArr);
    for (i = 0; i <= totalIterations; i++){
        ScoreValue = 3*i;
        newArr[1] = i;
        Safety(score - ScoreValue, newArr);
    }
    return;
}


//loops through all possible values for safeties and hands it off to touchdown2 each loop
void Safety(int score, int arr[]){
    int totalIterations = (score/2);
    int ScoreValue = 0;
    int i;
    for (i = 0; i <= totalIterations; i++){
        ScoreValue = 2*i;
        arr[2] = i;
        int newArr[5];
        identicalArray(arr, newArr);
        TouchDown2(score - ScoreValue, newArr);
    }
    return;
}

//loops through all values of touch downs with a +2 conversion and hands it off to touchdown1 each loop
void TouchDown2(int score, int arr[]){
    int totalIterations = (score/8);
    int ScoreValue = 0;
    for (int i = 0; i <= totalIterations; i++){
        ScoreValue = 8*i;
        arr[3] =i;
        int newArr[5];
        identicalArray(arr, newArr);
        TouchDown1(score - ScoreValue, newArr);
    }
    return;
}

//loopos through all values of touch downs with a +1 conversion and if the resulting score value
//then runs printCombo if the current value of plays is = to the overall score (known by the successive subtraction of play values all the way until now)
void TouchDown1(int score, int arr[]){
    int donesies = floor(score/7);
    int endscore = score - donesies*7;
    if (endscore == 0 && donesies >= 0){
        arr[4] = donesies;
        printCombo(arr);
    }
    return;
}