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

    long long mod = 1e9+7;
        
    bool flag=0; 
    int a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> n >> m;
    vector<int> v(n);
    vector<int> v2(m);
    map<int, int> mp;

    for(int i=0;i<n;i++){
        cin >> a;
        if(mp.find(a)==mp.end()){
            mp[a]=1;
            ans++;
        }
        else{
            mp[a]=0;
            ans--;
        }
    }
    for(int i=0;i<m;i++){
        cin >> a;
        if(mp.find(a)==mp.end()){
            mp[a]=1;
            ans++;
        }
        else{
            mp[a]=0;
            ans--;
        }
    }
    cout << ans;

    return 0;
}

