#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
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

    long long mod = 998'244'353;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    ll ans=0;

    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<ll> imos(n+1);
    imos[0]=v[0];
    for(int i=1;i<n;i++){
        imos[i]=v[i]-v[i-1];
    }
    imos[n]=-1*v[n-1];

    ll cnt=0;
    ll l=0;
    ll r=1;
    // for(int i=0;i<=n;i++){
    //     cout << imos[i] << ' ';
    // }

    while(r<=n&&l<=n){
        if(imos[l]>0 && imos[r]<0){
            ll x=min(imos[l], -1*imos[r]);
            cnt+=x;
            imos[l]-=x;
            imos[r]+=x;
            ans+=(r-l)*(r-l)*x;
        }
        else if(imos[r]>=0){
            r++;
        }
        else if(imos[l]<=0){
            l++;
        }
    }

    cout << cnt << ' ' << ans;

    return 0;
}