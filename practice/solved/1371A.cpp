#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int sticks = ceil((double) n / 2);
        cout << sticks << "\n";
    }
}