#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int chk[1001][1001][3];
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

    long long mod = 1'000'000'007;
    using P=pair<int,int>;

    long long a, b, c, d;
    long long ans = 0;

    string s;
    while(cin >> n >> m >> s){
        ans=0;
        vector<bool> bb(n+1, 0);
        vector<bool> oo(n+1, 0);
        vector<map<int, int>> vm(n+1);

        for(int i=0;i<s.size();i++){
            if(s[i]=='b')bb[i+1]=1;
            else oo[i+1]=1;
        }

        for(int i=0;i<m;i++){
            cin >> a >> b;
            if(bb[a] && oo[b] || bb[b]&&oo[a]){
                vm[a][b]=1;
                vm[b][a]=1;
            }
            // 서로 다른 그래프만 저장
        }

        ll tt;
        for(int i=1;i<=n;i++){
            if(oo[i]){
                // o를 기준으로 연결된 것을 확인.
                // b
                for(auto at1:vm[i]){ //1번째 b와 3번째 b 
                    ans +=(vm[i].size()-1)*(vm[at1.first].size()-1);
                    
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}