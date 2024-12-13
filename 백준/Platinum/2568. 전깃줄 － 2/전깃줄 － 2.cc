#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> n;
    vector <pair<int, int>> v;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    vector <int> dp(n);
    vector <int> elec;
    elec.push_back(v[0].second);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int l = -1;
        int r = elec.size();
        while(l+1<r){
            int mid = (l+r)/2;
            if(v[i].second>elec[mid]) l = mid;
            else r = mid;
        }
        if(l+1>=elec.size()){
            elec.push_back(v[i].second);
        }
        else{
            elec[l+1] = v[i].second;
        }
        dp[i] = l+1;
    }
    cout << n - elec.size() << '\n';
    c = elec.size()-1;
    vector <int> ans;
    for(int i=n-1;i>=0;i--){
        if(dp[i]==c){
            c--;
            continue;
        }
        else{
            ans.push_back(v[i].first);
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << '\n';
    }
    return 0;
}
//8 2 9 1 4 6 7 10