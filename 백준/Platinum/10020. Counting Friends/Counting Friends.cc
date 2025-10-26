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

    long long mod = 998'244'353;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    long long ans = 0;

    cin >> n;
    vector<P> v(n+1);
    ll tt=0;
    for(int i=0;i<n+1;i++){
        cin>>v[i].first;
        v[i].second=i+1;
        tt+=v[i].first;
    }
    sort(v.rbegin(), v.rend());

    vector<ll> nu(n+2, 0);
    for(int i=1;i<n+2;i++){
        nu[i]=nu[i-1]+v[i-1].first;
    }

    vector<int> ansv;

    for(int i=0;i<n+1;i++){
        flag=0;

        int tmp=v[i].first;
        long long cut = tt - tmp;

        if(cut%2==1 || cut<0 || cut>1LL*n*(n-1)) continue;

        vector<ll> deg;
        for(int t=0;t<n+1;t++){
            if(t==i) continue;
            ll dval = v[t].first;
            if(dval<0 || dval>n-1){ 
                flag=1;
                break;
            }
            deg.push_back(dval);
        }
        if(flag) continue;
        vector<ll> S(n+1, 0);
        for(int k=1;k<=n;k++) S[k]=S[k-1]+deg[k-1];

        for(int j=0;j<n;j++){
            int k=j+1;

            long long na=0;
            for(int t=k;t<n;t++){
                na +=(deg[t]>=k?k:deg[t]);
            }

            long long rhs = 1LL*k*(k-1)+na;
            if(S[k]>rhs){ 
                flag=1;
                break;
            }
        }

        if(flag==0){
            ansv.push_back(v[i].second);
        }
    }

    cout << ansv.size() << '\n';
    sort(ansv.begin(), ansv.end());
    for(int i=0;i<ansv.size();i++){
        cout << ansv[i] <<'\n';
    }

    return 0;
}