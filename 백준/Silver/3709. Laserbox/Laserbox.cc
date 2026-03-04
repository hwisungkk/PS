#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
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
        
    bool flag=1; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans=0;

    cin >> t;
    while(t-->0){
        cin >> n >> m; //보드 크기랑 터너 개수

        vector<vector<char>> turner(n+2, vector<char>(n+2, 0));
        for(int i=0;i<m;i++){
            cin >> a >> b;
            turner[a][b]=1;
        }

        int sx, sy;
        cin >> sx >> sy; //레이저 위치

        int dir=-1;
        if(sy==0) dir=0;            //북
        else if(sy==n+1) dir=2;     //남
        else if(sx==0) dir=1;       //동
        else if(sx==n+1) dir=3;     //서

        // 0=미방문, 1=방문중(스택), 2=완료
        vector<vector<array<int,4>>> color(n+2, vector<array<int,4>>(n+2));
        vector<vector<array<P,4>>> res(n+2, vector<array<P,4>>(n+2));

        function<void(int,int,int)> dfs = [&](int x, int y, int d){
            color[x][y][d]=1;

            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx==0 || nx==n+1 || ny==0 || ny==n+1){
                res[x][y][d]={nx,ny};
                color[x][y][d]=2;
                return;
            }

            int nd=d;
            if(turner[nx][ny]) nd=(d+1)%4;

            if(color[nx][ny][nd]==0){
                dfs(nx,ny,nd);
                res[x][y][d]=res[nx][ny][nd];
            }else if(color[nx][ny][nd]==1){
                res[x][y][d]={0,0};
            }else{
                res[x][y][d]=res[nx][ny][nd];
            }

            color[x][y][d]=2;
        };

        dfs(sx,sy,dir);
        cout << res[sx][sy][dir].first << ' ' << res[sx][sy][dir].second << '\n';
    }
    
    return 0;
}