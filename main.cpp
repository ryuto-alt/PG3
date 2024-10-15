#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3秒wait
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    srand(time(0)); 
    int diceRoll = rand() % 6 + 1;  
    int isEven = diceRoll % 2 == 0; 

    printf("奇数か偶数か (1: 奇数, 0: 偶数): ");

   
    int guess;
    scanf_s("%d", &guess);

    delay(3);

    //結果
    if (guess == 1 && !isEven) {
        printf("〇　出た目:%d,奇数です。\n", diceRoll);
    }
    else if (guess == 0 && isEven) {
        printf("〇　出た目:%d,偶数です。\n", diceRoll);
    }
    else {
        printf("×　出た目は%dで%sでした。\n", diceRoll, isEven ? "偶数" : "奇数");
    }

    return 0;
}
