#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> t;
    while(t-->0){
        cin >> n >> m;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        queue<int> q;
        q.push(0);
        vector<int> ans(3601, 1e8);
        ans[0]=0;
        
        if(3600%v[n-1]==0){
            ans[3600]=3600/v[n-1];
        }
        else{
            ans[3600]=3600/v[n-1]+1;
        }
        q.push(3600);
        while(!q.empty()){
            a = q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(a+v[i]>=0 && a+v[i]<=3600 && ans[a]+1 < ans[a+v[i]]){
                    ans[a+v[i]]=ans[a]+1;
                    q.push(a+v[i]);
                }
            }
        }
        for(int i=m;i<=3600;i++){
            if(ans[i]!=1e8){
                cout << ans[i] << ' ' << i-m << '\n';
                break;
            }
        }
    }


    return 0;
}