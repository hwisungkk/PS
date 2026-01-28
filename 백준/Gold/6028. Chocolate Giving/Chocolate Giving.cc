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

    cin >> n >> m >> t;

    vector<vector<P>> graph(n+1);
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dst(n+1, 1e9);
    dst[1]=0;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    pq.push({0,1});

    while(!pq.empty()){
        int cur=pq.top().first;
        int x=pq.top().second;
        pq.pop();

        for(int i=0;i<graph[x].size();i++){
            int go=graph[x][i].first;
            if(dst[go]>dst[x]+graph[x][i].second){
                dst[go]=dst[x]+graph[x][i].second;
                pq.push({dst[go], go});
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout << dst[i] << ' ';
    // }cout<<'\n';

    for(int i=0;i<t;i++){
        cin >> a >> b;
        cout << dst[a]+dst[b]<<'\n';
    }

    return 0;
}