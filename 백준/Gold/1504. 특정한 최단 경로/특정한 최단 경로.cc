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
    
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0;i<m;i++){
      cin >> a >> b >> c;
      graph[a].push_back({b,c});
      graph[b].push_back({a,c});
    }
    cin >> a >> b;
    priority_queue<pair<int, int>> pq;
    vector<int> dist_s(n+1, 1e8);
    pq.push({0, 1});
    dist_s[1]=0;
    while(!pq.empty()){
      int node = pq.top().second;
      int di = -pq.top().first;
      pq.pop();
      for(int i=0;i<graph[node].size();i++){
        if(dist_s[graph[node][i].first]>di+graph[node][i].second){
          dist_s[graph[node][i].first] = di+graph[node][i].second;
          pq.push({-dist_s[graph[node][i].first], graph[node][i].first});
        }
      }
    }
    vector<int> dist_v1(n+1, 1e8);
    pq.push({0, a});
    dist_v1[a]=0;
    while(!pq.empty()){
      int node = pq.top().second;
      int di = -pq.top().first;
      pq.pop();
      for(int i=0;i<graph[node].size();i++){
        if(dist_v1[graph[node][i].first]>di+graph[node][i].second){
          dist_v1[graph[node][i].first] = di+graph[node][i].second;
          pq.push({-dist_v1[graph[node][i].first], graph[node][i].first});
        }
      }
    }
    vector<int> dist_v2(n+1, 1e8);
    pq.push({0, b});
    dist_v2[b]=0;
    while(!pq.empty()){
      int node = pq.top().second;
      int di = -pq.top().first;
      pq.pop();
      for(int i=0;i<graph[node].size();i++){
        if(dist_v2[graph[node][i].first]>di+graph[node][i].second){
          dist_v2[graph[node][i].first] = di+graph[node][i].second;
          pq.push({-dist_v2[graph[node][i].first], graph[node][i].first});
        }
      }
    }

    int ans = min(dist_s[a]+dist_v1[b]+dist_v2[n], dist_s[b]+dist_v1[n]+dist_v2[a]);
    if(ans>=1e8)cout << "-1";
    else cout << ans;
    return 0;
}