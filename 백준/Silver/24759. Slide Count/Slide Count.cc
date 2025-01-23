#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, x, y;
    int mi = 1e9;
    cin >> n >> m;
    vector<int> v(n+2);
    vector<pair<int, int>> ans(n+1,{0,0});
    v[n+1] = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    int s=1, e=1;
    long long total=v[1];
    int index=0;
    while(s<=n){
        index++;
        if(ans[e].first==0){
            ans[e].first = index;
        }
        if(e+1>n){
            total-=v[s];
            if(ans[s].second==0)
                ans[s].second = index+1;
            s++;
        }
        else if(total+v[e+1]>m){
            total-=v[s];
            if(ans[s].second==0)
                ans[s].second = index+1;
            s++;
        }
        else {
            e++;
            total+=v[e];
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i].second - ans[i].first << '\n';
    }
    return 0;
}