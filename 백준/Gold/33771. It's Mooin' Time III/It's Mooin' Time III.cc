#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    string s;
    bool flag=0;
    cin >> n >> m;
    cin >> s;
    vector<vector<int>> v(26);
    for(int i=0;i<s.size();i++){
        v[s[i]-'a'].push_back(i+1);
    }
    for(int i=0;i<m;i++){
        long long ans=-1;
        cin >> a >> b;
        ch = s[a-1]; // start

        for(int j=0;j<26;j++){
            char ff = 'a'+j;
            if(ch == ff)continue;
            int l=0, r=v[j].size();
            while(l+1<r){
                int mid = (l+r)>>1;
                if(v[j][mid]<=b){ //close b
                    l = mid;
                }
                else r = mid;
            }
            if(l<=0)continue;
            //cout << v[j][l] << '\n';

            int ll=0, rr=l-1;
            while(ll+1<rr){
                int mid = (ll+rr)>>1;
                if(v[j][mid]<=(a+v[j][l])/2){ //close b
                    ll = mid;
                }
                else rr = mid;
            }
            if(ll<0 || ll >= l)continue;
            else ans = max(ans, ((long long)v[j][l]-v[j][ll])*(v[j][ll]-a));
            if(rr<0 || rr >= l)continue;
            else ans = max(ans, ((long long)v[j][l]-v[j][rr])*(v[j][rr]-a));
        }
        int j = ch-'a';
        while(s[a-1]==ch){
            a++;
            if(a==b){
                a=1e9;
                break;
            }
        }
        int l=0, r=v[j].size();
        while(l+1<r){
            int mid = (l+r)>>1;
            if(v[j][mid]<=b){ //close b
                l = mid;
            }
            else r = mid;
        }
        //cout << v[j][l] << '\n';

        int ll=0, rr=l-1;
        while(ll+1<rr){
            int mid = (ll+rr)>>1;
            if(v[j][mid]<=(a+v[j][l])/2){ //close b
                ll = mid;
            }
            else rr = mid;
        }
        if(ll>=0 && ll<l) ans = max(ans, ((long long)v[j][l]-v[j][ll])*(v[j][ll]-a));
        if(rr>=0 && rr<l) ans = max(ans, ((long long)v[j][l]-v[j][rr])*(v[j][rr]-a));

        cout << ans << '\n';
    }
    return 0;
}