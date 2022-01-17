#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int passengers = 0, max = 0;
    for (int i = 0; i < n; i++) {
        int off, on;
        cin >> off >> on;
        passengers += on - off;
        if (passengers > max)
            max = passengers;
    }
    cout << max << endl;
}