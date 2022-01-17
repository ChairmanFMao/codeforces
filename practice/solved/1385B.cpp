#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> known;
        for (int j = 0; j < n * 2; j++) {
            int a;
            cin >> a;
            if (count(known.begin(), known.end(), a) == 0)
                known.push_back(a);
        }
        string extra = " ";
        for (int j = 0; j < known.size(); j++) {
            if (j == known.size()-1)
                extra = "\n";
            cout << known[j] << extra;
        }
    }
}