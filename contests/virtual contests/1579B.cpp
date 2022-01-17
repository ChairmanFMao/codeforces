#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void shift (vector<int> *numbers, int start, int end, int move) {
    vector<int> saved;
    for (int i = start; i <= end; i++) {
        saved.push_back((*numbers)[i]);
    }
    for (int i = start; i <= end; i++) {
        (*numbers)[i] = saved[(i-start+move)%saved.size()];
    }
}

void solution() {
    int n;
    cin >> n;
    vector<int> sorted;
    vector<int> unsorted;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sorted.push_back(a);
        unsorted.push_back(a);
    }
    sort(sorted.begin(), sorted.end());
    vector<string> out;
    for (int i = 0; i < sorted.size(); i++) {
        if (sorted[i] != unsorted[i]) {
            for (int j = i+1; j < n; j++) {
                if (sorted[i] == unsorted[j]) {
                    shift(&unsorted, i, j, j - i);
                    string move = to_string(i+1) + " " + to_string(j+1) + " " + to_string(j-i) + "\n";
                    out.push_back(move);
                    break;
                }
            }
        }
    }
    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
    }
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