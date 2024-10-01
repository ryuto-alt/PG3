#include <stdio.h>

// 再帰的な賃金体系を計算する関数
double RecursiveWage(int hours, double prev_wage = 100) {
    if (hours == 1) {
        return prev_wage;
    }
    // 「前の1時間でもらった時給 * 2 - 50」で次の賃金を計算
    double current_wage = prev_wage * 2 - 50;
    return current_wage + RecursiveWage(hours - 1, current_wage);
}

// 一般的な賃金体系を計算する関数
double GeneralWage(int hours) {
    return 1072 * hours;
}

int main() {
    int hours;

    // 働く時間の入力 (scanf使用)
    printf("働く時間を入力してください: ");
    scanf_s("%d", &hours);

    // 各体系での総賃金を計算
    double total_recursive_wage = RecursiveWage(hours);
    double total_general_wage = GeneralWage(hours);

    // 結果の出力 (printf使用)
    printf("再帰的な賃金体系の総賃金: %.2f円\n", total_recursive_wage);
    printf("一般的な賃金体系の総賃金: %.2f円\n", total_general_wage);

    return 0;
}
