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
    vector<vector<int>> graph(n+1);

    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> par(n+1, 0);
    vector<int> chk(n+1, 0);
    ll tmp=0;

    function<void(int)> dfs=[&](int x){
        chk[x]=1;
        tmp++;
        //cout << "in: " << x << '\n';
        for(int i=0;i<graph[x].size();i++){
            if(!chk[graph[x][i]]){
                par[graph[x][i]]=x;
                dfs(graph[x][i]);
            }
        }
    };
    chk[1]=1;
    par[1]=-1;
    dfs(1);

    vector<int> load;

    ll xx=n;

    while(par[xx]!=-1){
        load.push_back(xx);
        xx=par[xx];
    }
    load.push_back(1); //1~N까지 경로임

    for(int i=1;i<=n;i++)chk[i]=0;
    
    for(int i=0;i<load.size();i++){
        chk[load[i]]=1;
        //cout << load[i] << ' ';
    }//cout<<'\n';

    ll ga=n-load.size();
    ans=ga*(ga-1)/2;

    for(int i=0;i<load.size();i++){
        for(int j=0;j<graph[load[i]].size();j++){
            tmp=0;
            if(!chk[graph[load[i]][j]]){
                //cout << graph[load[i]][j] << "??\n";
                dfs(graph[load[i]][j]);
                //cout << tmp << '\n';
                ans-=tmp*(tmp-1)/2;
            }
        }
    }

    cout << ans;

    return 0;
}