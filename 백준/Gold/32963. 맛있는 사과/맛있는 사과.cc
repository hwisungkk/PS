#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;
    using P = pair<int, int>;

    cin >> n >> m;

    vector<P> v(n);

    for(int i=0;i<n;i++)cin>>v[i].first;
    for(int i=0;i<n;i++)cin>>v[i].second;

    sort(v.begin(), v.end());
    vector<int> ansv(n, 0);

    int mi=-1;
    int cur=1;
    for(int i=n-1;i>=0;i--){
        if(mi<v[i].second){
            cur=1;
            mi=v[i].second;
        }
        else if(mi==v[i].second){
            cur++;
        }
        ansv[i]=cur;
    }

    for(int i=0;i<m;i++){
        cin >> a;
        auto it = lower_bound(v.begin(), v.end(), make_pair((int)a, -1));
        int b = (int)(it - v.begin());
        cout << ansv[b] << '\n';
    }
    
    return 0;
}