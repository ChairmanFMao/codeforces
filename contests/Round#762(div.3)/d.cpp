#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Friend {
    int best = -1;
    int secondBest = -1;
    int bestShop = -1;
    int secondBestShop = -1;
};

void solve() {
    int n, m;
    cin >> n >> m;
    int numbers[m][n];
    Friend friends[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> numbers[i][j];
            if (numbers[i][j] > friends[j].best) {
                friends[j].secondBest = friends[j].best;
                friends[j].secondBestShop = friends[j].bestShop;
                friends[j].best = numbers[i][j];
                friends[j].bestShop = i;
            } else if (numbers[i][j] > friends[j].secondBest) {
                friends[j].secondBest = numbers[i][j];
                friends[j].secondBestShop = i;
            }
        }

    map<int, int> shops;
    set<int> numberOfShops;
    int minHappiness = friends[0].best;
    for (int i = 0; i < n; i++) {
        shops[friends[i].bestShop]++;
        numberOfShops.insert(friends[i].bestShop);
        minHappiness = min(minHappiness, friends[i].best);
    }
    if (shops.size() <= m-1) {
        cout << minHappiness << "\n";
        return;
    }

    int maxSecond = 0;
    for (int i = 0; i < n; i++) {
        if (shops[friends[i].bestShop] == 1 && shops[friends[i].secondBestShop] > 0)
            maxSecond = max(maxSecond, friends[i].secondBest);
    }
    cout << min(maxSecond, minHappiness) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}