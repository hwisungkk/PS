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

    cin >> t;
    while(t-->0){
        cin >> n;
        if(n==1){
            cin>>a;
            cout<<a<<'\n';
            continue;
        }
        ll tt=0;
        vector<ll> v(n);
        bool plus=1; //다 양수면 최소빼야하고
        bool minus=1; //다 음수면 최대를 더해야 할듯?
        ll ma=-1e16;
        ll mi=1e16;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i]<0){
                plus=0;
                tt+=-1*v[i];
            }
            else if(v[i]>0){
                minus=0;
                tt+=v[i];
            }
            else{//0일 때?
                minus=0;
                plus=0;
            }
            ma=max(ma, v[i]);
            mi=min(mi, v[i]);
        }

        if(plus)tt=tt-2*mi;
        else if(minus)tt=tt+2*ma;
        cout << tt << '\n';
    }

    return 0;
}