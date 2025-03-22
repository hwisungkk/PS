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
    string s;
    long long ans=0;
    bool flag=0;

    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> money(n, vector<int>(m, 1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    if(v[0][0]==-1){
        cout << "-1";
        return 0;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-v[0][0], {0,0}});
    money[0][0]=v[0][0];
    while(!pq.empty()){
        int cur = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
            if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=m || v[x+dx[i]][y+dy[i]]==-1)continue;
            if(money[x+dx[i]][y+dy[i]] > cur+v[x+dx[i]][y+dy[i]]){
                money[x+dx[i]][y+dy[i]] = cur+v[x+dx[i]][y+dy[i]];
                pq.push({-money[x+dx[i]][y+dy[i]], {x+dx[i], y+dy[i]}});
            }
        }
    }

    if(money[n-1][m-1]==1e9)cout << "-1";
    else cout << money[n-1][m-1];

    return 0;
}