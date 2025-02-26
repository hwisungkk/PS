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
    int total=0;
    cin >> n;
    vector <int> v(100000,0);
    for(int i=0;i<n;i++){
        cin >> a;
        if(a>100000)v[100000]++;
        else v[a]++;
    }
    int ans = 0;
    m = n;
    m-=v[0];
    for(int i=1;i<=n;i++){
        if(m>=i)ans = i;
        m-=v[i];
    }
    cout << ans;


    return 0;
}