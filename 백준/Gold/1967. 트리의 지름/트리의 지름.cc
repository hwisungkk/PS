#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;

    cin >> n;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int ans=0;
    int len=0;
    pair<int, int> max1, max2;
    bool check[10001];
    function <void(int)> dfs = [&](int k){
        check[k]=1;
        ans = max(len, ans);
        for(int i=0;i<graph[k].size();i++){
            if(check[graph[k][i].first])continue;
            len+=graph[k][i].second;
            dfs(graph[k][i].first);
            len-=graph[k][i].second;
        }
    };
    for(int i=1;i<=n;i++){
        memset(check, 0, sizeof(check));
        len=0;
        dfs(i);
    }
    cout << ans;
    
    return 0;
}