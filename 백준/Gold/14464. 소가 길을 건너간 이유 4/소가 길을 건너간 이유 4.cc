#define ll long long
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
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k=0;
    long long ans = 0;

    string s;

    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int>> vp(m);
    vector<bool> chk(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<m;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(v.begin(),v.end());
    sort(vp.begin(), vp.end(), comp);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[j]>=vp[i].first && v[j]<=vp[i].second && !chk[j]){
                chk[j]=1;
                ans++;
                break;
            }
        }
    }
    cout << ans;

    

    return 0;
}
