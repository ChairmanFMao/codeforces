#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Algorithm works fine, just not efficient enough, timed out on test 14
// Timed out again even when taken out second vector
// Looked at tutorial and I need to use deque instead of vector for better efficiency
// Didn't manage to do it because I was using a vector and didn't know of deque ;-;

void solution() {
    int n;
    cin >> n;
    deque<int> output;
    int a;
    cin >> a;
    output.push_back(a);
    int begin = a;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        if (p < begin) {
            output.push_front(p);
            begin = p;
        }
        else
            output.push_back(p);
    }
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
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