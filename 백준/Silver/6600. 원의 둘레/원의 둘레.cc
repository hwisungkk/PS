#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=0; 

    double d1, d2, d3, d4, d5, d6;
    double PI = acos(-1);
    cout << fixed;
    cout.precision(2);
	for (double d1, d2, d3, d4, d5, d6; cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6;) {
		double d = hypot(d5 - d3, d6 - d4);
		double ax = d3 - d1, ay = d4 - d2, bx = d5 - d1, by = d6 - d2;
		double theta = acos((ax * bx + ay * by) / hypot(ax, ay) / hypot(bx, by));
		cout << d / sin(theta) * PI << '\n';
	}

    // a/sinA * pi 하면 댐

    return 0;
}
