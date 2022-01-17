#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Had a brute force solution but it timed out
// Looked at tutorial to find the solution

int power(int k) {
    if (k > 0) {
        return pow(10, k) + power(k-1);
    } else {
        return 1;
    }
}

void solution() {
    int n;
    cin >> n;
    int ordinary = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (i * power(j) <= n)
                ordinary++;
        }
    }
    cout << ordinary << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solution();
}