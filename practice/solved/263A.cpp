#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int numbers[5][5];
    int x, y;
    for (int i = 0; i < 25; i++) {
        cin >> numbers[i/5][i%5];
        if (numbers[i/5][i%5] == 1) {
            x = i/5;
            y = i%5;
        }
    }
    int move = abs(2 - x) + abs(2 - y);
    cout << move << "\n";
    return 0;
}