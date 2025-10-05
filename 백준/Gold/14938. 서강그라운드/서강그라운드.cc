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
    string s;

    cin >> n >> m >> t; //지역, 탐색, 길

    vector<int> v(n+1);
    vector<vector<int>> graph(n+1, vector<int>(n+1, 1e9));
    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    for(int i=1;i<=n;i++)cin>>v[i]; //템 개수

    for(int i=0;i<t;i++){
        cin >> a >> b >> c;
        graph[a][b]=c;
        graph[b][a]=c;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(graph[j][i]+graph[i][k]<graph[j][k]){
                    graph[j][k]=graph[j][i]+graph[i][k];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        ll tmp=0;
        for(int j=1;j<=n;j++){
            if(graph[i][j]<=m)tmp+=v[j];
        }

        ans=max(ans, tmp);
    }
    cout << ans;


    return 0;
}