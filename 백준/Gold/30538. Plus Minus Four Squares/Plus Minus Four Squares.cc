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
    using P=pair<int,int>;

    long long a, b, c, d;
    long long ans = 0;

    cin >> n;

    vector<int> v;

    for(int i=0;i*i<=n;i++){
        v.push_back(i*i);
    }

    int sz=v.size()-1;

    vector<int> z(4);

    function <void(int, int, int)> back=[&](int cnt, int tt, int buho){
        if(cnt==4){
            if(tt==n){
                //cout << z[0] << ' ' << z[1] << ' ' << z[2] << ' ' << z[3] << '\n';
                ans++;
            }
            return;
        }
        if(cnt==0){
            if(z[0]==0)return;
            back(1, z[0], 1);
        }
        else{
            if(z[cnt]==0){
                back(4, tt, 1);
            }
            else if(z[cnt]==z[cnt-1]){ // 같으면
                if(buho==1) back(cnt+1, tt+z[cnt], buho);
                else back(cnt+1, tt-z[cnt], buho);
            }
            else{
                back(cnt+1, tt+z[cnt], 1);
                back(cnt+1, tt-z[cnt], -1);
            }
        }
    };

    for(int i1=sz;i1>=0;i1--){
        for(int i2=i1;i2>=0;i2--){
            for(int i3=i2;i3>=0;i3--){
                for(int i4=i3;i4>=0;i4--){
                    z={v[i1], v[i2], v[i3], v[i4]};
                    back(0, 0, 0);
                }
            }
        }
    }

    if(n==0)ans++;
    cout << ans;

    return 0;
}