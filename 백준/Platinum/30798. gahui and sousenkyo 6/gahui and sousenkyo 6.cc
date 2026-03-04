#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
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

    cout << n << '\n';

    k=0;
    vector<ll> de;

    if(n%4==0){
        for(ll i=1;i<n;i++){
            if(i==n-1){
                de.push_back((i<<32)+(1LL<<59));
            }
            else{
                de.push_back(i<<32);
            }
        }
        de.push_back((1LL<<59)+m);
    }else if(n%4==1){
        for(ll i=1;i<=n-2;i++){
            if(i==n-2){
                de.push_back((i<<32)+(1LL<<59));
            }
            else{
                de.push_back(i<<32);
            }
        }
        for(ll i=1;i<=2;i++){
            if(i==2){
                de.push_back((1LL<<60)+(1LL<<59)+m);
            }
            else{
                de.push_back(1LL<<60);
            }
        }
    }else if(n%4==2){
        for(ll i=1;i<=n-3;i++){
            de.push_back(i<<32);
        }
        for(ll i=1;i<=3;i++){
            if(i==3){
                de.push_back((i<<60)+m);
            }
            else{
                de.push_back(i<<60);
            }
        }
    }else if(n%4==3){
        for(ll i=1;i<=n;i++){
            if(i==n){
                de.push_back((i<<32)+m);
            }
            else{
                de.push_back(i<<32);
            }
        }
    }
    sort(de.rbegin(), de.rend());
    for(int i=0;i<n;i++){
        cout<<de[i]<<'\n';
        k^=de[i];
    }

    //cout << '!' << k << '\n';
    
    return 0;
}