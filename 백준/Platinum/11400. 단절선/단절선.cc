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
    
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<P> ansv;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    t=0;

    vector<int> vis(n+1, 0);
    vector<int> par(n+1, 0);
    vector<int> low(n+1, 0); //이게 x보다 낮은 애들에서 올라 갈 수 있는 최대 위치?니까

    function <void(int)> dfs = [&](int x){
        t++;
        vis[x]=t;
        low[x]=vis[x];
        
        for(int y=0;y<graph[x].size();y++){
            if(par[x]==graph[x][y])continue;
            
            if(!vis[graph[x][y]]){
                par[graph[x][y]]=x;
                dfs(graph[x][y]);
                low[x]=min(low[graph[x][y]], low[x]);
            }
            else{
                low[x]=min(vis[graph[x][y]], low[x]);
            }
            //cout << "x: " << x << ',' << vis[x] << ' ' << "y: " << graph[x][y] << ',' << 
            low[graph[x][y]] << '\n';

            if(vis[x]<low[graph[x][y]]){
                //cout << "x: " << vis[x] << ' ' << "y: " << low[graph[x][y]] << '\n';
                ansv.push_back({min(x, graph[x][y]), max(x, graph[x][y])});
            }
        }
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }


    sort(ansv.begin(), ansv.end());
    cout << ansv.size()<<'\n';
    for(int i=0;i<ansv.size();i++){
        cout << ansv[i].first << ' ' << ansv[i].second<<'\n';
    }

    return 0;
}