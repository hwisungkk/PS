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

    string s1, s2;
    cin >> t;
    cout.fixed;
    cout.precision(12);

        for(int tc=1; tc<=t; ++tc){
        cin >> n;

        vector<double> v(n);
        vector<double> mi(n, 0.0);

        double tt = 0.0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            tt += v[i];
        }

        vector<int> live(n, 1);
        int cnt = n;
        double gi = 0.0;

        while(1){
            double score=0.0;
            for(int i=0;i<n;i++) if(live[i]) score+=v[i];

            gi=(tt+score)/(double)cnt;

            flag=0;
            for(int i=0;i<n;i++){
                if(live[i] && v[i]>gi+1e-12){
                    live[i]=0;
                    cnt--;
                    flag=1;
                }
            }
            if(!flag) break;
        }

        cout << "Case #" << tc << ":";
        for(int i=0;i<n;i++){
            double need = 0.0;
            if(live[i]) need = max(0.0, (gi-v[i])/tt)*100.0;
            cout << ' ' << need;
        }
        cout << '\n';
    }

    return 0;
}