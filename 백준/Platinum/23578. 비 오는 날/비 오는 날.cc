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
    vector<ll> v(n+1);
    priority_queue<P> pq;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        ans+=v[i]; //1씩을 넣어놓고
        pq.push({-1*(v[i])*(2*1+1), 1});
    }
    //총 다리 개수는 n-1, 차수 총 합은 2*(n-1)
    //1개 이상은 있어야 하고? n개보다는 작아야 하고
    //a(2*i+1)이 작아야하는 듯? i는 기존 간선이고 a는 학생 수

    for(int i=0;i<n-2;i++){
        ll val = -1*pq.top().first;
        ll cnt=pq.top().second;
        pq.pop();

        ans+=val;
        ll stu=val/(2*cnt+1);
        cnt++;
        pq.push({-1*stu*(2*cnt+1), cnt});
    }

    if(n==1)ans=0;
    cout << ans;
    //2 2 1 1
    //3 1 1 1
    return 0;
}