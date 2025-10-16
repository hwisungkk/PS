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

    ll a, b, c, d;
    ll ans = 0;
    int n, m;

    cin >> n >> m;

    vector<unordered_map<ll, ll>> graph(n+1);
    vector<pair<P, ll>> edge;
    vector<int> sz(n+1);

    edge.reserve(m);

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a][b]=c;
        graph[b][a]=c;
        sz[a]++; sz[b]++;
        edge.push_back({{a,b}, c});
    }

    for(int i=1;i<=n;i++){
        ll tmp=0;
        for(auto at:graph[i]) tmp+=at.second;
        ans=max(ans, tmp);
    }

    vector<int> id(n+1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin()+1, id.end(), [&](int x, int y){
        if(sz[x]!=sz[y]) return sz[x]<sz[y];
        return x<y;
    });
    vector<int> rk(n+1);
    for(int i=1;i<=n;i++) rk[id[i]]=i;

    vector<vector<pair<int,ll>>> fwd(n+1);
    for(int i=1;i<=n;i++) if(sz[i]) fwd[i].reserve(sz[i]);
    for(auto &e: edge){
        int x = (int)e.first.first;
        int y = (int)e.first.second;
        ll  w = e.second;
        if(rk[x]<rk[y]) fwd[x].push_back({y,w});
        else            fwd[y].push_back({x,w});
    }

    vector<int> vis(n+1, 0);
    vector<ll> from(n+1, 0);
    int tag = 0;

    for(int u=1; u<=n; u++){
        if(fwd[u].empty()) continue;
        ++tag;

        for(auto &nx : fwd[u]){
            int x = nx.first;
            vis[x]=tag;
            from[x]=nx.second;
        }
        for(auto &vv : fwd[u]){
            int v = vv.first;
            ll wuv = vv.second;
            for(auto &vx : fwd[v]){
                int x = vx.first;
                if(vis[x]==tag){
                    ll sum = wuv + from[x] + vx.second;
                    if(sum>ans) ans=sum;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}