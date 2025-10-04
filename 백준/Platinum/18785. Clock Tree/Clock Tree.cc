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
    using P=pair<int,int>;

    long long a, b, c, d;
    long long ans = 0;
    
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];

    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int t_odd=0;
    int t_even=0;
    int cnt_odd=0;
    int cnt_even=0;
    vector<bool> visit(n+1, 0);

    function <void(int, bool)> dfs=[&](int x, bool ok){
        visit[x]=1;
        if(!ok){
            t_odd+=v[x];
            cnt_odd++;
        }
        else{
            t_even+=v[x];
            cnt_even++;
        }

        for(int i=0;i<graph[x].size();i++){
            if(!visit[graph[x][i]])
                dfs(graph[x][i], !ok);
        }
    };
    dfs(1, 0);

    t_odd%=12;
    t_even%=12;

    if(t_odd==t_even)cout<<n;
    else if((t_odd+1)%12==t_even)cout<<cnt_even;
    else if((t_even+1)%12==t_odd)cout<<cnt_odd;
    else cout<<0;

    return 0;
}