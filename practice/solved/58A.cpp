#include <iostream>
using namespace std;

int main(void) {
    string greeting;
    cin >> greeting;
    char hello[] = {'h','e','l','l','o'};
    int pointer = 0;
    for (int i = 0; i < greeting.length(); i++) {
        if (greeting[i] == hello[pointer]) {
            pointer++;
        } if (pointer == 5) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}