#include <iostream>
#define ll long long
using namespace std;

// Read the tutorial for this one, math fried my brain

void solution(int n) {
	ll out = 0;
	for (ll i = 1; i <= ((n - 1) / 2); i++)
		out += i * i;
	out *= 8;
	cout << out << "\n";
}

int main(void) {
	int t;
	cin >> t;
	int arr[t];
	for (int i = 0; i < t; i++)
		cin >> arr[i];
	for (int i = 0; i < t; i++)
		solution(arr[i]);
	return 0;
}
