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
    long long ans = 0;

    cin >> n >> m;

    vector<ll> dp(m+1, 0);

    for(int i=0;i<n;i++){
        cin >> a >> b >> c; //무게, 가치, 개수
        t=1;
        while(c>0){
            t=min(c,t);
            c-=t;
            ll tmp=a*t;
            for(int j=m;j>=a*t;j--){
                dp[j]=max(dp[j-a*t]+b*t, dp[j]);
            }
            t*=2;
        }
    }
    for(int i=0;i<=m;i++)ans=max(ans, dp[i]);
    cout << ans;

    return 0;
}