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
        
    bool flag=1; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans=0;

    string s;
    cin >> n;
    cin >> s;
    vector<vector<int>> pp(n+1, vector<int>(n+1, -1));

    function <int(int, int)> pal=[&](int st, int ed){
        if(st>ed){
            return 0;
        }
        if(pp[st][ed]!=-1)return pp[st][ed];
        if(s[st]==s[ed]){
            return pp[st][ed]=pal(st+1, ed-1);
        }
        else{
            return pp[st][ed]=min(pal(st+1, ed), pal(st, ed-1))+1;
        }
    };

    cout << pal(0, n-1);

    return 0;
}