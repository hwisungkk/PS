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
    string s;

    cin >> n >> m;

    vector<vector<P>> graph(n+1);
    vector<ll> dst(n+1, 1e16);
    vector<ll> gil(n+1);

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    int st, ed;

    cin >> st >> ed;
    dst[st]=0;

    gil[st]=-1;

    priority_queue<P> pq;
    pq.push({0, st});

    while(!pq.empty()){
        ll cha=-1*pq.top().first;
        ll cur=pq.top().second;
        pq.pop();

        if(dst[ed]<cha)break;
        for(int i=0;i<graph[cur].size();i++){
            ll to=graph[cur][i].first;
            ll val=graph[cur][i].second;

            if(cha+val<dst[to]){
                dst[to]=cha+val;
                pq.push({-1*dst[to], to});
                gil[to]=cur;
            }
        }
    }

    cout << dst[ed] <<'\n';

    int cnt=0;
    int x=ed;
    vector<ll> ansv;
    while(x!=-1){
        ansv.push_back(x);
        cnt++;
        x=gil[x];
    }

    cout << ansv.size() <<'\n';
    for(int i=ansv.size()-1;i>=0;i--){
        cout << ansv[i] << ' ';
    }


    return 0;
}