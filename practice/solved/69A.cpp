#include <iostream>
using namespace std;

int main(void) {
    int repeats, x = 0, y = 0, z = 0, tempx, tempy, tempz;
    cin >> repeats;
    for (int i = 0; i < repeats; i++) {
        cin >> tempx >> tempy >> tempz;
        x += tempx;
        y += tempy;
        z += tempz;
    }
    string out = x == 0 && y == 0 && z == 0 ? "YES" : "NO";
    cout << out << endl;
}