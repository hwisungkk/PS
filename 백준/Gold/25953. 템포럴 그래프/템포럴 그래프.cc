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

    cin >> n >> t >> m; //정점 개수, 시간, 시간 마다 간선 개수고
    int st, to;
    cin >> st >> to;

    vector<vector<ll>> dst(t+1, vector<ll>(n, 1e16));
    dst[0][st]=0;

    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            dst[i][j]=min(dst[i][j], dst[i-1][j]);
        }
        for(int j=0;j<m;j++){
            cin >> a >> b >> c; //길이랑 가중치
            if(dst[i-1][a]<1e16){
                dst[i][b]=min({dst[i][b], dst[i-1][a]+c});
            }
            if(dst[i-1][b]<1e16){
                dst[i][a]=min(dst[i][a], dst[i-1][b]+c);
            }
        }
    }

    // for(int i=1;i<=t;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dst[i][j]<<' ';
    //     }cout<<'\n';
    // }
    if(dst[t][to]==1e16)cout<<"-1\n";
    else cout << dst[t][to];

    return 0;
}