#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 奇数か偶数かを判定するためのコールバック関数
void checkOddEven(int diceRoll, int (*callback)(int), int guess) {
    int result = callback(diceRoll);

    // 正解か不正解かを判定
    if ((result == 1 && guess == 1) || (result == 0 && guess == 2)) {
        printf("正解！\n");
    }
    else {
        printf("不正解！\n");
    }
}

// 奇数か偶数かを判定する関数 (奇数なら1、偶数なら0を返す)
int isOdd(int number) {
    return number % 2;
}

int main() {
    srand(time(NULL)); 
    int diceRoll = rand() % 6 + 1; 

    int guess; 
    printf("サイコロの出目が奇数か偶数かを予想してください (奇数...1 / 偶数...2): ");
    scanf_s("%d", &guess);

    // 出目をコールバック関数で判定
    checkOddEven(diceRoll, isOdd, guess);

   
    printf("実際のサイコロの出目: %d\n", diceRoll);

    return 0;
}
