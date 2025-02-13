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
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;
    vector<pair<int, int>> vp;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(a<b)vp.push_back({b,a});
        else vp.push_back({a,b});
    }
    if(vp.size()==0){
        for(int i=0;i<n-1;i++){
            cout << "N";
        }
        return 0;
    }
    sort(vp.begin(),vp.end());
    string ans = "";
    int point = 0;
    for(int i=2;i<=n;i++){
        int cnt=0;
        while(i == vp[point].first){
            cnt++;
            point++;
        }
        if(cnt==0)ans+='N';
        else if(cnt==i-1)ans+='E';
        else break;
    }
    if(ans.length()==n-1)cout << ans;
    else cout << "-1";

    return 0;
}