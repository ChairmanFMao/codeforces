#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int wealth[n];
    int max;
    cin >> max;
    wealth[0] = max;
    for (int i = 1; i < n; i++) {
        cin >> wealth[i];
        if (wealth[i] > max)
            max = wealth[i];
    }
    int required = 0;
    for (int i = 0; i < n; i++)
        required += max - wealth[i];
    cout << required << "\n";
}