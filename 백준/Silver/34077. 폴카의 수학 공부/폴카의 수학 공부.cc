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

    cin >> t;
    while(t-->0){
        cin >> n;
        string s;
        cin >> s;
        bool mi=0;
        flag=0;
        for(int i=1;i<2*n+1;i+=2){
            if(!mi&&s[i]=='-')mi=1;
            else if(mi&&s[i+1]!='0'){
                flag=1;
                break;
            }
        }
        if(!flag)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}