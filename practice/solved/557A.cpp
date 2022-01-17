#include <iostream>
#define ll long long
using namespace std;

// Had to peek the solution, maths ;-;
// I was using a O(n^2) algorithm which would always time out

void solution(int n, int x) {
    int occurs = 0;
    for (ll i = 1; i <= n; i++) {
        if (x % i == 0 && x / i <= n)
            occurs++;
    }
    cout << occurs << "\n";
}

int main(void) {
	int n, x;
    cin >> n >> x;
    solution(n, x);
	return 0;
}
