#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int min, max, records = 0;
    cin >> min;
    max = min;
    for (int i = 0; i < n - 1; i++) {
        int score;
        cin >> score;
        if (score > max) {
            max = score;
            records++;
        } else if(score < min) {
            min = score;
            records++;
        }
    }
    cout << records << endl;
}