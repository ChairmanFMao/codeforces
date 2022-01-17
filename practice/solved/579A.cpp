#include <iostream>
using namespace std;

int main(void) {
    int x;
    cin >> x;
    unsigned int power = 2147483648;
    int dedecutions = 0;
    while (x != 0) {
        if (x >= power) {
            x -= power;
            dedecutions++;
        }
        power /= 2;
    }
    cout << dedecutions << endl;
    return 0;
}