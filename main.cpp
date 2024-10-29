#include <iostream>
#include <cstdio>

template <typename T>
class Compare {
public:
    // 2つの引数のうち小さい方を返す関数
    T Min(const T& value1, const T& value2) {
        return (value1 < value2) ? value1 : value2;
    }
};

int main() {
    // int型、float型、double型の3パターンでインスタンスを生成してテスト
    Compare<int> intComp;
    Compare<float> floatComp;
    Compare<double> doubleComp;

    int intResult = intComp.Min(10, 20);
    float floatResult = floatComp.Min(5.5f, 3.2f);
    double doubleResult = doubleComp.Min(8.9, 4.6);

    printf("Int型の最小値: %d\n", intResult);
    printf("Float型の最小値: %.2f\n", floatResult);
    printf("Double型の最小値: %.2f\n", doubleResult);

    return 0;
}
