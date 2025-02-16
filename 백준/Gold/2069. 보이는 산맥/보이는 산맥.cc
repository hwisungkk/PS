#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] ={-1,1,0,0};
int dy[4]={0,0,1,-1};
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first)return 1;
    else if(a.first==b.first){
        if(a.second<b.second)return 1;
        else return 0;
    }
    else return 0;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    char c1, c2, c3;

    cin >> n;
    vector<pair<int,int>> v;
    long long ans=0;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);

    // 밑변 b-a , 높이 b-a*2
    ans += (v[0].second-v[0].first)*(v[0].second-v[0].first);

    int c_x=v[0].first, c_y=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first > c_y){
            ans += (v[i].second-v[i].first)*(v[i].second-v[i].first);
            c_x = v[i].first, c_y=v[i].second;
        }
        else if(v[i].second > c_y){
            ans -= (c_y-v[i].first)*(c_y-v[i].first);
            ans += (v[i].second-v[i].first)*(v[i].second-v[i].first);
            c_y = v[i].second;
        }
        else continue;
    }

    cout << ans;

    return 0;
}