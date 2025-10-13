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

    long long mod =  1'000'000'007;
    using P=pair<ll,ll>;
    using PP = pair<P,P>;

    long long a, b, c, d;
    long long ans = 1e9;

    cin >> t;

    while(t-->0){
        cin >> n >> m;
        flag=0;
        ans=1e9;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)cin>>v[i];

        auto press = [&](ll i, vector<int>& diff) {
            int L=max(1LL, i-m);
            int R=min(n, i+m);
            diff[L]^=1;
            if (R+1<=n+1) diff[R+1]^=1;
        };

        int tt = min(m, n);
        int best = 1e9;

        for (int mask=0;mask<(1<<tt);mask++) {
            vector<int> diff(n+2, 0);
            int cnt = 0;
            bool ok = true;

            for (int k=1; k<=tt; ++k) {
                if (mask & (1 << (k-1))) {
                    press(k, diff);
                    cnt++;
                }
            }

            int roll=0; 
            int last=n-m;

            for (int i=1; i<=n; ++i) {
                roll ^= diff[i];       
                int curr = v[i] ^ roll; 

                if (i<=last) {
                    if (curr==1) {
                        int p=i+m;
                        press(p, diff);
                        cnt++;

                        roll^=1;
                    }
                } else {
                    if (curr == 1) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) best=min(best, cnt);
        }

        if (best==1e9) cout << "impossible\n";
        else cout<<best<<'\n';
    }

    return 0;
}