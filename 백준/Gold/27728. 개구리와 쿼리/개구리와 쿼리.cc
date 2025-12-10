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
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> nu(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> nu2(n+1, vector<ll>(n+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>v[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=0;j--){
            nu[i][j]=v[i][j+1]+nu[i][j+1];
        }
    }

    for(int j=0;j<=n;j++){
        nu2[1][j]=nu[1][j];
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=n;j++){
            nu2[i][j]=min(nu[i][j], nu2[i-1][j]);
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<nu[i][j]<<' ';
    //     }cout<<'\n';
    // }cout<<"==============\n";

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<nu2[i][j]<<' ';
    //     }cout<<'\n';
    // }cout<<"==============\n";

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;

        ans=nu[a][b-1];

        for(int j=b-1;j<=n;j++){
            ans=min(ans, nu[a][b-1]-nu[a][j]+nu2[a-c][j]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}