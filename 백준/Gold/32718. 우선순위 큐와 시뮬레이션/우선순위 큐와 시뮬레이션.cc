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
    long long ans = 1e9;

    cin >> n >> m >> t;
    vector<ll> v(n+1, 0);
    vector<ll> Q(t+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]%=m;
    }
    for(int i=1;i<=t;i++)cin>>Q[i];
    vector<ll> nu(t+1, 0);

    sort(v.begin(), v.end());

    for(int i=1;i<=t;i++){
        nu[i]=Q[i]+nu[i-1];

        nu[i]%=m;
        //cout << nu[i] << ' ';
    }//cout<<'\n';

    for(int i=1;i<=t;i++){
        ll key=m-nu[i]-1;

        int l=0, r=n+1;

        while(l+1<r){
            int mid=(l+r)>>1;

            if(v[mid]<=key)l=mid;
            else r=mid;
        }
        //cout << "l: " << l << '\n';
        if(l==0) cout<<(v[n]+nu[i])%m<<' '; //0이면 뒤로
        else cout << v[l]+nu[i] << ' ';
    }

    return 0;
}