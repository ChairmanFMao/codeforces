#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, memory limit exceeded test 5, used a breadth first search to test it
// Failed second try, WA test 45
// Thinking about making an implementation of dijkstras algorithm
// Accepted third try! I ended up using dijkstra's algorithm in the end and it worked very efficiently

void solve() {
    int n, numbers[3];
    cin >> n >> numbers[0] >> numbers[1] >> numbers[2];

    map<int,int> paths;
    queue<int> processing;
    processing.push(0);
    while (!processing.empty()) {
        int current = processing.front();
        processing.pop();
        if (current >= n)
            continue;
        for (int i = 0; i < 3; i++) {
            if (paths[current+numbers[i]] < paths[current]+1) {
                paths[current+numbers[i]] = paths[current]+1;
                processing.push(current+numbers[i]);
            }
        }
    }
    cout << paths[n] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}