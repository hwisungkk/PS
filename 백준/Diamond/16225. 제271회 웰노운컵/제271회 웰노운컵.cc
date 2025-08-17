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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    set<ll> st;

    cin >> n;
    vector<ll>va(n);
    vector<ll>vb(n);

    for(int i=0;i<n;i++)cin>>va[i];
    for(int i=0;i<n;i++)cin>>vb[i];

    // b가 작을때네?

    vector<pair<ll,ll>> vp(n);
    for(int i=0;i<n;i++){
        vp[i].first=vb[i];
        vp[i].second=va[i];
    }
    sort(vp.begin(),vp.end()); //b기준 정렬

    priority_queue<ll> pq;

    ans+=vp[0].second;
    for(int i=1;i<n-1;i+=2){
        pq.push(vp[i].second);
        pq.push(vp[i+1].second);
        ans+=pq.top();
        //cout << pq.top() << '\n';
        pq.pop();
    }
    
    

    cout << ans;

    return 0;
}