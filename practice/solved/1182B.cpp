#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 7, edge case
// Failed second try, WA test 37, just a little oversight in the algorithm
// Epicly accepted third try! The initial algorithm was good however, I just didn't account for
// some specific cases with unusual circumstances

vector<string> picture;
int w, h;

int neighbors(int x, int y) {
    int out = 0;
    if (x > 0)
        if (picture[x-1][y] == '*')
            out++;
    if (x < w-1)
        if (picture[x+1][y] == '*')
            out++;
    if (y > 0)
        if (picture[x][y-1] == '*')
            out++;
    if (y < h-1)
        if (picture[x][y+1] == '*')
            out++;
    return out;
}

void solve() {
    cin >> w >> h;
    // w rows and h columns, very confusing
    for (int i = 0; i < w; i++) {
        string a;
        cin >> a;
        picture.push_back(a);
    }

    if (w < 3 || h < 3) {
        cout << "NO" << "\n";
        return;
    }
    
    // If there is a lone * with no neighbors the picture isn't valid, or if there is a * with 3 neighbors
    bool plus = 0;
    pair<int,int> mid;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            // Check picture[i][j]'s neighbors
            // If i detect a plus it will start with a * with one neighbor and it will be the top part
            if (picture[i][j] == '*') {
                if (neighbors(i,j) == 4 && !plus) {
                    mid = {i,j};
                    plus = 1;
                } else if (neighbors(i,j) == 4 && plus) {
                    cout << "NO" << "\n";
                    return;
                }
            }
        }
    }

    if (!plus) {
        cout << "NO" << "\n";
        return;
    }

    // This is a set of all of the points that are in the plus symbol
    set<pair<int,int>> connected;
    connected.insert(mid);
    int x = mid.first, y = mid.second;
    while (x >= 0 && picture[x][y] == '*') {
        connected.insert({x,y});
        x--;
    }
    x = mid.first;
    while (x < w && picture[x][y] == '*') {
        connected.insert({x,y});
        x++;
    }
    x = mid.first;
    while (y >= 0 && picture[x][y] == '*') {
        connected.insert({x,y});
        y--;
    }
    y = mid.second;
    while (y < h && picture[x][y] == '*') {
        connected.insert({x,y});
        y++;
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (picture[i][j] == '*' && connected.count({i,j}) == 0) {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}