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
    for(int tc=1;tc<=t;tc++){
        ans=1e9;
        cin >> n >> m;
        
        vector<ll> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<ll> nu(n+1, 0);

        for(int i=1;i<=n;i++){
            nu[i]=nu[i-1]+v[i-1];
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                a=nu[j]-nu[i];

                if(a>m)break;

                if(a==m){
                    if(ans>j-i){
                        ans=j-i;
                    }
                    continue;
                }

                b=m-a; // 남은거
                int l=j+1, r=j+2;

                while(r<=n){
                    //cout << r << ' ' << l << ' ' << nu[r]-nu[l] << '\n';
                    if(l==r)r++;
                    if(nu[r]-nu[l]>b){
                        l++;
                    }
                    else if(nu[r]-nu[l]==b){
                        if(ans>(j-i)+(r-l)){
                            ans=(j-i)+(r-l);
                        }
                        l++;
                    }
                    else r++;
                }
            }
        }

        // for(int i=0;i<=n;i++){
        //     cout << nu[i] << ' ';
        // }cout <<'\n';
        if(ans==1e9)ans=-1;
        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}