#include <iostream>
#include <algorithm>
#include <string>	
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    long long n, m, k, t;
    int idx = 1;
	int x, y;
	int sum;
	string s1, s2;
	string result;

	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	x = stoi(s1);
	y = stoi(s2);

	sum = x + y;
	result = to_string(sum);
	reverse(result.begin(), result.end());

	cout << stoi(result) << '\n';

	return 0;
}