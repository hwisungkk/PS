#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int n, m, k;
    int t;
    string s;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> m;
    sort(v.begin(), v.end());
    int cnt=0;
    int l = 0;
    int r = n-1;
    while(l<r){
        if(v[l]+v[r]==m){
            cnt++;
            r--;
        }
        else if(v[l]+v[r]<m)l++;
        else r--;
    }
    cout << cnt;
    return 0;
}
