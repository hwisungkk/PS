#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int parent[1001];
int ran[1001];
const double PI = acos(-1.0);
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
    long long ans=0;

    cin >> n >> m;
    vector<ll> v(m); //회차마다 사탕을 꺼내는 횟수
    for(int i=0;i<m;i++){ 
        cin >> v[i];
    }
    vector<ll> nu(m+1, 0);
    for(int i=1;i<=m;i++){
        nu[i]=nu[i-1]+v[i-1];
    }
    ll tt=0;
    vector<ll> ba(n); //아이가 먹고 싶어하는 사탕의 개수
    int idx=0;
    for(int i=0;i<n;i++){
        cin >> ba[i];
        auto at=lower_bound(nu.begin(), nu.end(), ba[i])-nu.begin();
        if(at>m)cout<<"Go away!\n";
        else cout<<at<<'\n';
    }

    return 0;
}