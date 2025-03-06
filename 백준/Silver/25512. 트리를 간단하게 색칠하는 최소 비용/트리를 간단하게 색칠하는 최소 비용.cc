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
    int n, m, k, t;
    int o_1, o_2;

    cin >> n;
    vector<vector<int>> graph(n);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        vp.push_back({a,b});
    }
    vector<int> odd;
    vector<int> even;

    function <void(int, int)> dfs = [&](int k, int flag){
        if(flag%2==0)odd.push_back(k);
        else even.push_back(k);

        for(int i=0;i<graph[k].size();i++){
            dfs(graph[k][i], flag+1);
        }
    };
    dfs(0,0);
    long long bl = 0;
    long long wh = 0;
    for(int i=0;i<odd.size();i++){
        bl += vp[odd[i]].first;
        wh += vp[odd[i]].second;
    }
    for(int i=0;i<even.size();i++){
        wh += vp[even[i]].first;
        bl += vp[even[i]].second;
    }
    cout << min(wh, bl);

    return 0;
}