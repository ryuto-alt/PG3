#include <iostream>
#include <thread>

using namespace std;

void PrintThread(uint32_t num) {
    cout << "thread No" << num << endl;
}

int main() {
    thread t1(PrintThread, 1);
    t1.join();  // t1の処理が終わるまで待機

    thread t2(PrintThread, 2);
    t2.join();  // t2の処理が終わるまで待機

    thread t3(PrintThread, 3);
    t3.join();  // t3の処理が終わるまで待機

    return 0;
}
