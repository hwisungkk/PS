#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> m;
    vector <pair<int, int>> p;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        p.push_back({a,b});
    }
    double ma = 10e9;
    for(int i=1;i<m;i++){
        if(sqrt(pow(p[0].first-p[i].first, 2)+pow(p[0].second-p[i].second, 2)) < ma){
            ma = sqrt(pow(p[0].first-p[i].first, 2)+pow(p[0].second-p[i].second, 2));
            a = p[0].first;
            b = p[0].second;
            c = p[i].first;
            k = p[i].second;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << a << ' ' << b << '\n' << c << ' ' << k << '\n';
    cout << ma;
    return 0;
}
//8 2 9 1 4 6 7 10