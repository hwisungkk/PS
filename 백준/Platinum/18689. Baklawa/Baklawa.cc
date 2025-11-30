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

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    ll total=0;

    cin >> t;
    while(t-->0){
        cin >> a >> b >> c >> d;
        if(d==0){
            if(((a-1)^(b-1)^(c-1))==0)cout<<"Bob\n";
            else cout<<"Alice\n";
            continue;
        }
        ll x_m=1e18, x_M=0;
        ll y_m=1e18, y_M=0;
        ll z_m=1e18, z_M=0;

        for(int i=0;i<d;i++) {
            ll x, y, z;
            cin >> x >> y >> z;

            if(x<x_m) x_m=x;
            if(x>x_M) x_M=x;
            if(y<y_m) y_m=y;
            if(y>y_M) y_M=y;
            if(z<z_m) z_m=z;
            if(z>z_M) z_M=z;
        }

        ll x_l=x_m-1;
        ll x_r=a-x_M;
        ll y_l=y_m-1;
        ll y_r=b-y_M;
        ll z_l=z_m-1;
        ll z_r=c-z_M;

        ll dv=x_l^x_r^y_l^y_r^z_l^z_r;
        if(dv!=0)cout<<"Alice\n";
        else cout<<"Bob\n";
    }

    return 0;
}