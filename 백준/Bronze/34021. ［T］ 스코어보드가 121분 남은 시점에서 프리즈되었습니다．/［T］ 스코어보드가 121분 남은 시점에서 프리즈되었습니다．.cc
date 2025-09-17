#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> k;
    while(k-->0){
        cin >> n >> m >> t;
        vector<int> v(n);
        ans = t;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]!=-1){
                ans=max(m-v[i],ans);
            }
        }

        cout << "The scoreboard has been frozen with ";
        cout << ans;
        if(ans==1)cout<<" minute ";
        else cout<<" minutes ";
        cout << "remaining.\n";
    }

    return 0;
}