#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {

    list<const char*> rosen = { "田端", "日暮里", "西日暮里" };

    // 駅を追加
    rosen.push_back("上野");
    rosen.push_back("東京");

    // 1回目の表示
    for (list<const char*>::iterator itr = rosen.begin();
        itr != rosen.end();
        itr++)
    {
        cout << *itr << endl;
    }

    cout << "=================" << endl;

    // 2回目の表示
    for (list<const char*>::iterator itr = rosen.begin();
        itr != rosen.end();
        itr++)
    {
        cout << *itr << endl;
    }

    return 0;
}
