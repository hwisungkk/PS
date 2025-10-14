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
    vector<ll> v(n+2, 0);

    for(int i=0;i<n;i++)cin>>v[i];

    for(int i=0;i<n;i++){
        ll tmp;
        while(v[i]>0){
            if(v[i+1]>0){
                if(v[i+2]>0){
                    if(v[i]>v[i+1]){ //앞이 뒤보다 크면 1개를 사야만 하는 듯?
                        ans+=(v[i]-v[i+1])*3;
                        v[i]=v[i+1];
                    }
                    else{ //이제 처음이랑 두번째는 같거나 앞에가 더 작고
                        if(v[i+1]>v[i+2]){  // 1 3 2 느낌이거나 3 3 2 느낌이겠죠
                            tmp=min(v[i], v[i+1]-v[i+2]); // 이만큼을 2개씩 빼면
                            ans+=tmp*5;
                            v[i]-=tmp;
                            v[i+1]-=tmp;
                        }
                        else{ //증가 수열이면?
                            tmp=v[i];
                            ans+=7*tmp;
                            v[i]-=tmp;
                            v[i+1]-=tmp;
                            v[i+2]-=tmp;
                        }
                    }
                }
                else{
                    tmp=min(v[i], v[i+1]); //2개만 있을 때
                    ans+=tmp*5;
                    v[i]-=tmp;
                    v[i+1]-=tmp;
                }
            }
            else{
                ans+=v[i]*3; // 1개만 덜렁 있을 때
                v[i]=0;
            }
        }
    }

    cout << ans;

    return 0;
}