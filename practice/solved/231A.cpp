#include <iostream>
using namespace std;

int main(void) {
    int lines, know, a, solved = 0;
    cin >> lines;
    for (int i = 0; i < lines; i++) {
        know = 0;
        for (int j = 0; j < 3; j++) {
            cin >> a;
            if (a == 1) know++;
        }
        if (know >= 2) solved++;
    }
    cout << solved << endl;
}