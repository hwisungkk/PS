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
}bool cmp1(pair<ll,ll> A, pair<ll,ll> B){ // 앞자리
    if(A.first==B.first)return A.second<B.second;
    return A.first<B.first;
}
bool cmp2(pair<ll,ll> A, pair<ll,ll> B){ //뒷자리
    if(A.second==B.second)return A.first<B.first;
    return A.second<B.second;
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
    string s;

    cin >> a >> b >> c >> d;

    if(1800-a-b-c-d>=300)cout<<"Yes";
    else cout << "No";


    return 0;
}