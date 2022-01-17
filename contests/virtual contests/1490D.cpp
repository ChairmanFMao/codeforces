#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Took so long but was worth it!

vector<int> numbers;
vector<pair<int,int>> pairs;

void create(int start, int end, int depth) {
    int biggest = 0, bi = 0;
    for (int i = start; i < end; i++) {
        if (numbers[i] > biggest) {
            biggest = numbers[i];
            bi = i;
        }
    }
    if (start != bi) {
        create(start, bi, depth+1);
    }
    if (bi + 1 != end) {
        create(bi + 1, end, depth+1);
    }
    pairs.push_back({biggest, depth});
}

void solve() {
    int n;
    cin >> n;
    int biggest = 0, bi = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > biggest) {
            biggest = a;
            bi = i;
        }
        numbers.push_back(a);
    }
    pairs.push_back({biggest, 0});
    if (0 != bi)
        create(0, bi, 1);
    if (bi+1 != n)
        create(bi + 1, n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (numbers[i] == pairs[j].first) {
                cout << pairs[j].second << " ";
                break;
            }
        }
    }
    cout << "\n";
    pairs.clear();
    numbers.clear();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}