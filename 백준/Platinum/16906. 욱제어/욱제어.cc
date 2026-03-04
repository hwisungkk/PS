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
    vector<int> v(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v2[i]=v[i];
    }
    sort(v2.begin(), v2.end());
    vector<P> vp(n);
    for(int i=0;i<n;i++){
        vp[i]={v[i], i};
    }
    sort(vp.begin(), vp.end());
    vector<string> ansv(n);

    map<string, int> mp;
    bool ok=0;

    function <void(string, int, int)> dfs=[&](string ss, int sz, int idx){
        if(ok)return;
        for(char x='0';x<='1';x++){
            if(ok)break;
            if(mp.find(ss+x)!=mp.end()){ //이게 있다는거 잖아.
                continue;
            }else{
                if(ss.size()+1==sz){
                    mp[ss+x]=1;
                    ok=1;
                    ansv[vp[idx].second]=ss+x;
                    ss+=x;
                    while(ss.size()>0 && ss[ss.size()-1]=='1'){
                        ss.pop_back();
                        mp[ss]=1;
                    }
                    return;
                }
                else{
                    dfs(ss+x, sz, idx);
                }
            }
        }
        if(!ok){
            flag=1;
            return;
        }
    };

    for(int i=0;i<n;i++){
        ok=0;
        dfs("", v2[i], i);
        if(flag)break;
    }
    // for(auto a:mp){
    //     cout<<"!";
    //     cout << a.first<< " ";
    // }cout<<'\n';

    if(flag)cout<<"-1";
    else{
        cout << "1\n";
        for(int i=0;i<ansv.size();i++){
            cout << ansv[i]<<'\n';
        }
    }

    return 0;
}