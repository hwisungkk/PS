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
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    cin >> a >> b;
    vector<int>v(a);
    vector<int>v2(a-1);
    for(int i=0;i<a;i++)cin>>v[i];
    for(int i=0;i<a-1;i++)v2[i]=v[i]+v[i+1];
    sort(v2.begin(), v2.end());
    cout << b*(v2[0]);
    return 0;
}