#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int parent[1001];
int ran[1001];
const double PI = acos(-1.0);
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
    using P=pair<ll,ll>;

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans=0;

    cin >> n;
    vector<P> vp(n);

    for(int i=0;i<n;i++){
        cin>>vp[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>vp[i].second;
    }
    // 가장 효율 좋게 만들기. v1은 증가, v2는 감소하는 방향으로
    // 일단 정렬을 한번 하고
    sort(vp.begin(), vp.end());
    vector<int> nv(n);
    for(int i=0;i<n;i++){
        nv[i]=vp[i].second;
        //여태까지 나온 것보다 큰 수가 나오면 일단 걔는 새로 만들어야 하고.
        //작은애가 나오면 걔를 제일 차이가 조금 나는 높은 애한테 넣는게 맞을 것 같은데
    }
    //걍 이분탐색으로 찾으면 되는듯.
    vector<int> ad;
    ans++;
    ad.push_back(nv[0]);
    for(int i=1;i<n;i++){
        int idx=lower_bound(ad.begin(), ad.end(), nv[i])-ad.begin();
        if(idx==ad.size()){
            ans++;
            ad.push_back(nv[i]);
        }
        else{
            ad[idx]=nv[i];
        }
    }
    cout << ans;

    return 0;
}

//5 2 3 4 1