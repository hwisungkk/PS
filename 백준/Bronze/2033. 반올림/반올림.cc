#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, tmp = 10;
	cin >> N;
	while (N > tmp) {
		int val = (N / (tmp / 10)) % 10;
		if (val < 5) N -= val * (tmp / 10);
		else N += (10 - val) * (tmp / 10);
		tmp *= 10;
	}

	cout << N;
}