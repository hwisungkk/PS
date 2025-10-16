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

    cin >> n >> m;

    vector<unordered_map<ll, ll>> graph(n+1);
    vector<pair<P, ll>> edge;

    vector<int> sz(n+1);

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a][b]=c;
        graph[b][a]=c;
        sz[a]++;
        sz[b]++;
        edge.push_back({{a,b}, c});
    }

    //조건에 맞으려면 한 점에서 쭉 나오거나
    //삼각형이 이뤄질 때

    for(int i=1;i<=n;i++){ //이건 한점에서 뻗는애들
        ll tmp=0;
        for(auto at:graph[i]){
            tmp+=at.second;
        }
        ans=max(ans, tmp);
    }

    for(auto at:edge){
        ll x=at.first.first;
        ll y=at.first.second;

        if(sz[x]<sz[y]){
            for(auto at2:graph[x]){
                if(graph[y].find(at2.first)!=graph[y].end()){
                    ans=max(ans, at.second+graph[y][at2.first]+at2.second);
                }
            }
        }
        else{
            for(auto at2:graph[y]){
                if(graph[x].find(at2.first)!=graph[x].end()){
                    ans=max(ans, at.second+graph[x][at2.first]+at2.second);
                }
            }
        }
    }
    cout << ans;

    return 0;
}