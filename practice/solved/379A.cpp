#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    int hours = 0, out = 0;
    while (a > 0) {
        a--;
        out++;
        hours++;
        if (out >= b) {
            out -= b;
            a++;
        }
    }
    cout << hours << endl;
    return 0;
}