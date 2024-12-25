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

    int t = 1000;
    vector<int>v(4);
    for(int i=0;i<4;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    t= v[3]-v[2]-v[1]+v[0];
    if(t<0)cout<<-1*t;
    else cout <<t;

    return 0;
}