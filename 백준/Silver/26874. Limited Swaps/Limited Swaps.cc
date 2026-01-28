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

    cin >> n;
    vector<int> v1(n+1);
    vector<int> v2(n+1);

    for(int i=1;i<=n;i++)cin>>v1[i];
    for(int i=1;i<=n;i++)cin>>v2[i];

    vector<int> ansv;

    for(int i=1;i<=n;i++){
        int j=i;
        while(v1[j]!=v2[i]){
            j++;
            if(j>n){
                flag=1;
                break;
            }
        }

        int l=i, r=j;

        while(l<r){
            if(abs(v1[r]-v1[r-1])>=2){
                ansv.push_back(r-1);
                swap(v1[r], v1[r-1]);
                r--;
            }
            else break;
        }
        while(l<r){
            if(abs(v1[l]-v1[l+1])>=2){
                ansv.push_back(l);
                swap(v1[l], v1[l+1]);
                l++;
            }
            else break;
        }
        if(v1[i]!=v2[i])flag=1;
        if(flag)break;
    }

    if(flag){
        cout<<"-1";
        return 0;
    }

    cout << ansv.size() << '\n';
    string sp="";
    for(int i=0;i<ansv.size();i++){
        cout << sp << ansv[i];
        sp=' ';
    }

    return 0;
}