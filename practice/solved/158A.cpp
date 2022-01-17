#include <iostream>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int scores[n];
    for (int i = 0; i < n; i++)
        cin >> scores[i];
    int boundary = scores[k-1];
    int winners = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= boundary && scores[i] > 0)
            winners++;
    }
    cout << winners << "\n";
    return 0;
}