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
#include <map>
using namespace std;
vector<vector<int>> graph(26);
int a, b, c, d;
long long n, m, t, k;
vector<int> ba(26);
int ans = -1;
int cur = 0;
vector<int> visit(26, 0);
void back(int hp, int node){
    if(hp==0 && node==b){
        ans = max(ans, cur);
        return;
    }
    else if(hp==0)return;
    else if(hp>0 && visit[b]>=2)return;

    for(int i=0;i<graph[node].size();i++){
        if(visit[graph[node][i]]==0){
            cur += ba[graph[node][i]];
            visit[graph[node][i]]++;
            back(hp-1, graph[node][i]);
            cur -= ba[graph[node][i]];
            visit[graph[node][i]]--;
        }
        else if(visit[graph[node][i]]==1){
            visit[graph[node][i]]++;
            back(hp-1, graph[node][i]);
            visit[graph[node][i]]--;
        }
        else continue;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    bool flag=0; 

    cin >> n >> m; //노드 개수, 체력
    cin >> a >> b; //시작 노드, 도착해야 하는 노드

    for(int i=1;i<=n;i++){
        cin >> ba[i];
    }

    vector<int>mae(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> mae[i];
    }

    for(int i=0;i<n-1;i++){
        cin >> c >> d;
        if(mae[c]==0&&mae[d]==0){
            graph[c].push_back(d);
            graph[d].push_back(c);
        }
    }

    visit[a]=1;
    cur+=ba[a];
    back(m, a);
    cout << ans;

    return 0;
}

