#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int chk[100][100][4];
int parent[1001];
int ran[1001];
int find(int u) {
   if (u == parent[u]) return u;
   return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
   u = find(u);
   v = find(v);
   if (u == v) return;
   if (ran[u] > ran[v]) swap(u, v); 
   parent[u] = v;                                                                                                                                                                                                        
   if (ran[u] == ran[v]) ran[v]++;
}
ll gcd(ll x, ll y){
    if(x<y)swap(x,y);

    while(y!=0){
        ll tmp=y;
        y=x%y;
        x=tmp;
    }
    return x;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using P=pair<ll,ll>;

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> n;
    vector<P> vp(n);
    int mi=1e9+1, ma=-1;
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
        if(mi>vp[i].second)mi=vp[i].second;
        if(ma<vp[i].second)ma=vp[i].second;
    }
    ll l=mi, r=ma;

    while(l+1<r){
        ll mid=(l+r)/2;
        ans=0;
        //cout << "mid: " << mid << '\n';

        for(int i=0;i<n;i++){
            ans+=vp[i].second;
            ans-=mid;

            if(i<n-1){
                ll dst = vp[i+1].first-vp[i].first;
                if(ans>=0 && ans<dst)ans=0;
                else ans-=dst;
            }

            //cout << '!' << ans << '\n';
        }

        if(ans<0)r=mid;
        else l=mid;
    }

    cout << l;

    return 0;
}