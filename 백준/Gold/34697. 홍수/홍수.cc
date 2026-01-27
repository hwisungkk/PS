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

    cin >> n >> m;
    vector<int> high(n+1);
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=n;i++){
        cin>>high[i];
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;

        if(high[a]>high[b]){
            graph[b].push_back(a);
        }
        else if(high[b]>high[a]){
            graph[a].push_back(b);
        }
    }
    vector<bool> ck(n+1, 0);

    function <void(int)> dfs=[&](int x){
        ck[x]=1;
        //cout<<x<<'\n';
        //cout<<graph[x].size() << "sz\n";

        for(int i=0;i<graph[x].size();i++){
            if(!ck[graph[x][i]])dfs(graph[x][i]);
        }
    };

    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a;
        dfs(a);
    }

    for(int i=1;i<=n;i++){
        //cout << ck[i] << ' ';
        if(!ck[i])flag=1;
    }

    if(flag)cout<<"flood";
    else cout<<"no flood";

    return 0;
}