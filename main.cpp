#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

// コールバック関数
void DispResult(int* s, int* kye, int dice) {
    if (dice == *kye) {
        if (dice == 0)
            printf("%dで丁(偶数)でした。当たり\n", dice);
        else
            printf("%dで半(奇数)でした。当たり\n", dice);
    }
    else {
        if (dice == 1)
            printf("%dで半(奇数)でした。はずれ\n", dice);
        else
            printf("%dで丁(偶数)でした。はずれ\n", dice);
    }
}

// setTimeout関数
void setTimeout(std::function<void(int*, int*, int)> p, int second, int kye, int dice) {
    for (int i = 0; i < second; i++) {
        Sleep(1000);
        printf("%d...\n", second - i);
    }
    p(&second, &kye, dice);
}

int main() {
    int kye;
    srand(static_cast<unsigned int>(time(NULL)));

    printf("丁(偶数)なら0、半(奇数)なら1を打つ\n");
    scanf_s("%d", &kye);

    if (kye == 0) {
        puts("あなたは丁(偶数)を選びました");
    }
    else {
        puts("あなたは半(奇数)を選びました");
    }

    // 乱数を生成（ここで固定しておく）
    int dice = rand() % 2;

    // ラムダ式でコールバック関数を指定
    std::function<void(int*, int*, int)> p =
        [](int* s, int* kye, int dice) { DispResult(s, kye, dice); };

    // 3秒後に結果を表示
    setTimeout(p, 3, kye, dice);

    return 0;
}
