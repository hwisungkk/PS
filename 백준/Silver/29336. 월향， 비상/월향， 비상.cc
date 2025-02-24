#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    cin >> n >> m;
    vector<long long> v(n);
    vector<pair<long long, long long>> con(m);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<m;i++){
        cin >> con[i].first >> con[i].second;
    }
    sort(con.begin(), con.end());
    //이분 탐색인줄 알았는데 최대를 넣는게 이득이네?
    long long ans=0;
    int point = n-1;
    for(int i=0;i<m;i++){
        while(con[i].second > ans){
            if(point<0){
                cout << "-1";
                return 0;
            }
            ans += (v[point]+con[i].first);
            point--;
        }
    }
    for(int i=point;i>=0;i--){
        ans+=(v[i]+con[m-1].first);
    }
    
    cout << ans;

    return 0;
}