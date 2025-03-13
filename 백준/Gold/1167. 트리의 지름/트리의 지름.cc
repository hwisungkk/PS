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
    for(int i=0;i<n;i++){
        cin >> a;
        while(1){
            cin >> b;
            if(b==-1)break;
            cin >> c;
            graph[a].push_back({b,c});
        }
    }
    int len=0;
    int ans=0;
    int point=-1;
    vector<bool> visited(n+1, 0);
    function <void(int)> dfs = [&](int k){
        visited[k]=1;
        for(int i=0;i<graph[k].size();i++){
            if(visited[graph[k][i].first])continue;
            len+=graph[k][i].second;
            dfs(graph[k][i].first);
            len-=graph[k][i].second;
        }
        if(ans < len){
            ans = len;
            point = k;
        }

    };
    dfs(1);
    fill(visited.begin(), visited.end(), 0);
    dfs(point);
    cout << ans;
    
    return 0;
}