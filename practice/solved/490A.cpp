#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> one, two, three;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1)
            one.push_back(i);
        else if (t == 2)
            two.push_back(i);
        else if (t == 3)
            three.push_back(i);
    }
    int minimum = min(min(one.size(), two.size()), three.size());
    cout << minimum << "\n";
    for (int i = 0; i < minimum; i++)
        cout << one[i] << " " << two[i] << " " << three[i] << "\n";
}