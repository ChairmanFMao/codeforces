#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    double average = (double) sum / n;
    cout << average << endl;
}