#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;
    int a[n];
    vector<int> out;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n/2; i++) {
        out.push_back(a[i]);
        out.push_back(a[n-i-1]);
    }
    if (n%2 == 1)
        out.push_back(a[n/2]);
    for (int i = 0; i < n; i++) {
        cout << out[i] << " ";
    }
    cout << "\n";
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