#include <iostream>
#include <string>

class Enemy {
public:
    // 状態遷移関数ポインタの型定義
    typedef void (Enemy::* StateFunc)();

    // コンストラクタ
    Enemy() : currentState(&Enemy::meleeState) {}

    // 状態遷移メソッド
    void changeState(StateFunc newState) {
        currentState = newState;
    }

    // 状態を更新して表示
    void update() {
        (this->*currentState)();
    }

private:
    // 各状態の関数
    void meleeState() {
        std::cout << "近接攻撃中...\n";
        changeState(&Enemy::rangedState);
    }

    void rangedState() {
        std::cout << "射撃攻撃中...\n";
        changeState(&Enemy::retreatState);
    }

    void retreatState() {
        std::cout << "離脱中...\n";
        changeState(&Enemy::meleeState); // ループさせるために最初に戻る
    }

    // 現在の状態関数へのポインタ
    StateFunc currentState;
};

int main() {
    Enemy enemy;


    for (int i = 0; i < 3; ++i) {
        enemy.update();
    }

        return 0;
    }
