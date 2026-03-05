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
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans=0;

    cin >> n;
    string s;
    cin >> s;

    vector<bool> cac(n+2, 0); //1부터 시작으로 함.
    for(int i=0;i<n;i++){
        if(s[i]=='#')cac[i+1]=1;
    }
    vector<vector<ll>> dp(n+2, vector<ll>(454, 0)); //해봤자 1000번 이상 점프 불가능?
    dp[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<453;j++){ //1칸 가거나, j+1칸 가거나
            if(dp[i][j]){
                if(!cac[i+1]){
                    dp[i+1][j]+=dp[i][j];
                }
                if(i+j+1<=n && !cac[i+j+1]){
                    dp[i+j+1][j+1]+=dp[i][j];
                    dp[i+j+1][j+1]%=mod;
                }
                else if(i+j+1>n){
                    dp[n+1][0]+=dp[i][j];
                    dp[n+1][0]%=mod;
                }
            }
        }
    }
    // for(int i=1;i<=n+1;i++){
    //     for(int j=0;j<=5;j++){
    //         cout << dp[i][j] <<' ';
    //     }cout<<'\n';
    // }
    for(int i=0;i<=453;i++){
        ans+=dp[n+1][i];
        ans%=mod;
    }
    cout << ans;

    return 0;
}