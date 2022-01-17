#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Read question properly, there are normally some hints hidden in there for the guidelines of what you should be doing

int main(void) {
    int n, m, pos = 1;
    long long moves = 0;
    cin >> n >> m;
    vector<int> tasks;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        tasks.push_back(a);
    }
    for (int i = 0; i < tasks.size(); i++) {
        moves += tasks[i] >= pos ? tasks[i] - pos : n - pos + tasks[i];
        pos = tasks[i];
    }
    cout << moves << endl;
    return 0;
}