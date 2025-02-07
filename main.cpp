#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

// リスト全体を表示する関数
void printList(const list<const char*>& l) {
    for (auto station : l) {
        cout << station << endl;
    }
}

int main(void) {

    list<const char*> eki_list{
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro",
        "Takadanobaba", "Sin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
        "Ebisu", "Meguro", "Gotanda", "Osaki", "Sinagawa", "Tamachi", "Hamamatsucho",
        "Shimbashi", "Yurakucho"
    };

    // 1970年のリスト表示
    printf("1970年\n");
    printList(eki_list);

    // 2019年： "Tabata"の前に "Nishi-Nippori" を挿入
    for (auto it = eki_list.begin(); it != eki_list.end(); ++it) {
        if (*it == "Tabata") {
            eki_list.insert(it, "Nishi-Nippori");
            break;
        }
    }
    printf("\n2019年\n");
    printList(eki_list);

    // 2022年： "Tamachi" の前に "Takanawa Gateway" を挿入
    for (auto it = eki_list.begin(); it != eki_list.end(); ++it) {
        if (*it == "Tamachi") {
            eki_list.insert(it, "Takanawa Gateway");
            break;
        }
    }
    printf("\n2022年\n");
    printList(eki_list);

    return 0;
}
