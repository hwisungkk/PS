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
    cin >> n >> m; //점, 간선

    int start;
    cin >> start;
    vector<int> dist(n+1, 1e9);
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    priority_queue<pair<int, int>> pq;
    dist[start]=0;
    pq.push({0, start});
    while(!pq.empty()){
        int node = pq.top().second;
        int di = -pq.top().first;
        pq.pop();
        for(int i=0;i<graph[node].size();i++){
            int dest = graph[node][i].first;
            int move = graph[node][i].second; 
            if(dist[dest] > di + move){
                dist[dest] = di + move;
                pq.push({-dist[dest], dest});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i]==1e9){
            cout << "INF\n";
        }
        else cout << dist[i] << '\n';
    }

    return 0;
}