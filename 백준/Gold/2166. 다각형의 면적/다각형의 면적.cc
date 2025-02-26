#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    vector <pair<int, int>> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    double ans =0;
    for(int i=1;i<n-1;i++){
        double a = v[0].first, b = v[0].second;
	    double c = v[i].first, d = v[i].second;
	    double e = v[i+1].first, f = v[i+1].second;

	ans += (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
    }

    cout << fixed;
	cout.precision(1);
	cout << abs(ans);

    return 0;
}