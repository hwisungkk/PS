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

    long long mod = 998'244'353;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    long long ans = 0;

    vector<vector<P>> graph(10001);
    while(cin >> a >> b >> c){
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<bool> vis(10001, 0);
    vector<bool> dst(10001, 0);

    int mi=-1;
    int idx;

    function<void(int, int)> dfs = [&](int x, int cur){
        dst[x]=cur;
        vis[x]=1;
        if(mi<cur){
            idx=x;
            mi=cur;
        }
        for(int i=0;i<graph[x].size();i++){
            int to=graph[x][i].first;
            int val=graph[x][i].second;

            if(!vis[to]){
                dfs(to, cur+val);
            }
        }
    };
    dfs(1, 0);

    for(int i=0;i<=10000;i++){
        vis[i]=0;
        dst[i]=0;
    }
    //cout << idx << ' '  << mi << '\n';
    mi=-1;
    dfs(idx, 0);
    
    cout << mi;

    return 0;
}