#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    int n, m, t, k;
    bool flag=0; 

    string s;

    double d1, d2, d3;

    cin >> d1 >> d2;

    d3 = d1 / (d1 - (d2/100)*d1);

    d3-=1;
    d3*=100;

    cout.precision(8);
    cout << fixed;

    cout << d3;

    return 0;
}
