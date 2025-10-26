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

    cin >> n >> m;
    vector<ll> cha(n, 0);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cha[a]++;
        cha[b]++;
    }

    // cha에서 총 빼야 하는 수가 2*(m-n+1)인거지.
    int del = 2*(m-n+1); // 지울양.

    vector<P> vp(n);

    for(int i=0;i<n;i++){
        vp[i]={cha[i], i};
    }
    sort(vp.rbegin(), vp.rend()); //큰거부터 빼고

    // for(int i=0;i<n;i++){
    //     cout << vp[i].first << ' ';
    // }cout<<'\n';

    int cnt=0; // 달라지는 개수

    for(int i=0;i<n;i++){
        if(del>0){
            cnt++;
            if(del>vp[i].first-1){
                del-=(vp[i].first-1); //최소 1개는 있어야해서
                vp[i].first=1;
            }
            else{
                vp[i].first-=del;
                del=0;
            }
        }
        else break;
    }

    // for(int i=0;i<n;i++){
    //     cout << vp[i].first << ' ' << vp[i].second << '\n';
    // }cout<<'\n';

    cout << cnt << '\n';
    cout << n << ' ' << n-1 << '\n';    

    sort(vp.begin(), vp.end());

    queue<int> one; //경로찍기
    for(int i=0;i<n;i++){
        if(vp[i].first==1){
            one.push(vp[i].second);
        }
        else{
            cout << one.front() << ' ' << vp[i].second << '\n';
            one.pop();
            if(--vp[i].first==1){ //1개 남으면 넣어
                one.push(vp[i].second);
            }
            else i--;
        }
    }
    cout << one.front()<< ' ';
    one.pop();
    cout << one.front() << '\n';
    
    return 0;
}