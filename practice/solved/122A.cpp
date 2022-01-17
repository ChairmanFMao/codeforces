#include <iostream>
using namespace std;

int main(void) {
    int number;
    cin >> number;
    int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 777, 774, 747, 744};
    for (int i = 0; i < sizeof(lucky)/sizeof(lucky[0]); i++) {
        if (number % lucky[i] == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}