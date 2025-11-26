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
struct fire{
    int r;
    int c;
    int mass;
    int speed;
    int dir;
};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000'007;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    long long ans=0;

    cin >> n;
    vector<int> cha(n+1, 0);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        cha[a]++;
        cha[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    int leaf=0;
    int root=-1;
    vector<int> chk(n+1, 0);
    for(int i=1;i<=n;i++){
        if(cha[i]!=1 && cha[i]!=3){
            cout<<"-1";
            return 0;
        }
        if(cha[i]==1){
            chk[i]=1;
            q.push(i);
            leaf++;
        }
    }

    vector<ll> depth(100, 0);
    
    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int i=0;i<graph[x].size();i++){
            if(chk[graph[x][i]]==0){
                chk[graph[x][i]]=chk[x]+1;
                q.push(graph[x][i]);
            }
            else if(chk[graph[x][i]]==chk[x]+1){
                depth[chk[graph[x][i]]]++;
                q.push(graph[x][i]);
            }
            if(depth[chk[graph[x][i]]]==leaf-1){
                root=graph[x][i];
            }
        }
    }

    if(root==-1){
        cout<<"-1";
        return 0;
    }
    cout << "1\n" << root;

    return 0;
}