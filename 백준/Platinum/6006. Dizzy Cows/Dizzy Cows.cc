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

    cin >> n >> m >> k;
    vector<map<int, int>> graph(n+1);
    vector<int> deg(n+1, 0); //나가는 개수?
    vector<int> rank(n+1, 0);
    for(int i=0;i<m;i++){ //단방향
        cin >> a >> b;
        if(graph[b].find(a)==graph[b].end()){
            graph[b][a]=1; //역으로 넣고
            deg[a]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
            rank[i]=1;
        }
    }
    while(!q.empty()){
        int ff=q.front();
        q.pop();
        for(auto at:graph[ff]){
            int to=at.first;
            deg[to]--;
            if(deg[to]==0){
                rank[to]=rank[ff]+1;
                q.push(to);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout << rank[i] << ' ';
    // }
    for(int i=0;i<k;i++){
        cin >> a >> b;

        if(rank[a]>rank[b])cout<<a<<' '<<b<<'\n';
        else if(rank[a]<rank[b])cout<<b<<' '<<a<<'\n';
        else {
            if(a>b)cout<<a<<' '<<b<<'\n';
            else cout<<b<<' '<<a<<'\n';
        }
    }

    return 0;
}