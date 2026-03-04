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

    cout<<fixed;
    cout.precision(5);

    long double dd=0;
    while(cin>>k>>n){
        vector<vector<long double>> dp(k+1, vector<long double>(n, 0));
        dd=0;
    

        for(int i=0;i<=k;i++){
            dp[i][0]=1/((long double)k+1);
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                if(j>0)dp[j][i]+=dp[j-1][i-1]/(k+1);
                dp[j][i]+=dp[j][i-1]/(k+1);
                if(j<k)dp[j][i]+=dp[j+1][i-1]/(k+1);
            }
        }

        for(int i=0;i<=k;i++){
            dd+=dp[i][n-1];
        }

        cout << dd*100<<'\n';
    }

    return 0;
}