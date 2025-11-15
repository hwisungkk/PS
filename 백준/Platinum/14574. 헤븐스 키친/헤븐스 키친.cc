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
    vector<pair<double, double>> vp(n+1);

    for(int i=1;i<=n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    vector<vector<ll>> graph(n+1, vector<ll>(n+1, -1));
    vector<vector<bool>> chk(n+1, vector<bool>(n+1, 0));
    vector<bool> vis(n+1, 0);

    priority_queue<pair<ll, pair<int, int>>> pq;
    ll mx=-1, stx, sty;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            graph[i][j]=(vp[i].second+vp[j].second)/abs(vp[i].first-vp[j].first);
            //cout << i << ' ' << j << ' ' << graph[i][j] << '\n';
            if(mx<graph[i][j]){
                mx=graph[i][j];
                stx=i;
                sty=j;
            }
        }
    }
    vector<int> deg(n+1, 0);
    pq.push({mx, {stx, sty}});
    int pick=1;
    while(!pq.empty()&&pick<n){
        ll val=pq.top().first;
        ll xx=pq.top().second.first;
        ll yy=pq.top().second.second;
        pq.pop();

        if(chk[xx][yy] || chk[yy][xx] || vis[yy])continue;

        ans+=graph[xx][yy];
        pick++;
        chk[xx][yy]=1;
        chk[yy][xx]=1;
        deg[xx]++;
        deg[yy]++;

        if(!vis[xx]){
            for(int i=1;i<=n;i++){
                if(!chk[xx][i])pq.push({graph[xx][i], {xx, i}});
            }
            vis[xx]=1;
        }
        if(!vis[yy]){
            for(int i=1;i<=n;i++){
                if(!chk[yy][i])pq.push({graph[yy][i], {yy, i}});
            }
            vis[yy]=1;
        }
    }
    cout<<ans<<'\n';

    queue<int> q;
    for(int i=1;i<=n;i++){
        //cout << deg[i] << ' ';
        if(deg[i]==1)q.push(i);
    }

    while(!q.empty()){
        int z=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(chk[z][i]){
                chk[z][i]=0;
                chk[i][z]=0;
                cout<< i << ' ' << z << '\n';
                deg[i]--;
                deg[z]--;
                if(deg[i]==1)q.push(i);
            }
        }
    }

    return 0;
}