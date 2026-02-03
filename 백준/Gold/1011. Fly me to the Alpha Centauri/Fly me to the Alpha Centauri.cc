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

    cin >> t;
    while(t-->0){
        cin >> a >> b;

        n=b-a;
        for(ll i=sqrt(n)-1;;i++){
            k=i;
            if(i*(i+1)>=n)break;
        }
        if(k*(k+1)-k>=n){
            cout<<2*k-1<<'\n';
        }
        else cout << 2*k <<'\n';
    }

    return 0;
}

//n(n-1)