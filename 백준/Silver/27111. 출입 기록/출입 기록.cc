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

    cin >> n;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(mp.find(a)==mp.end()){ //없으면
            if(b==0){
                ans++;
                mp[a]=0;
            }
            else mp[a]=1;
        }
        else{
            if(b==0){
                if(mp[a]==1){
                    mp[a]=0;
                }
                else{
                    ans++;
                }
            }
            else if(b==1){
                if(mp[a]==0){
                    mp[a]=1;
                }
                else ans++;
            }
        }
    }
    for (auto at:mp) {
        if (at.second==1)ans++;
    }

    cout << ans;

    return 0;
}