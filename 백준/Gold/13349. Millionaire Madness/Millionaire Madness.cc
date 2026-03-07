#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int parent[1001];
int ran[1001];
const double PI = acos(-1.0);
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
    long long ans=0;

    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll> (m));
    vector<vector<bool>> vis(n, vector<bool> (m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }

    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    int x=0, y=0;

    ll l=-1, r=1e9+1;
    queue<P> q;
    function<bool(int)> ok =[&](int chk){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++){
                if(cx+dx[i]<n && cx+dx[i]>=0 && cy+dy[i]<m && cy+dy[i]>=0 && 
                    !vis[cx+dx[i]][cy+dy[i]] && v[cx][cy]+chk>=v[cx+dx[i]][cy+dy[i]]){
                    q.push({cx+dx[i], cy+dy[i]});
                    vis[cx+dx[i]][cy+dy[i]]=1;
                }
            }
        }

        if(vis[n-1][m-1])return true;
        else return false;
    };
    while(l+1<r){
        ll mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid;
    }
    cout << r;

    return 0;
}