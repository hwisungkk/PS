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
    
    t=0;
    while(1){
        t++;
        cin >> n >> m;
        if(n==0 && m==0)break;
        vector<vector<int>> graph(n+1);
        vector<bool> check(n+1, 0);
        for(int i=0;i<m;i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool flag = 1;
        function <void(int, int)> dfs=[&](int k, int pre){
            check[k]=1;
            for(int i=0;i<graph[k].size();i++){
                if(!check[graph[k][i]]){
                    dfs(graph[k][i], k);
                }
                else if(pre!=graph[k][i])flag=0;
            }
        };
        int cnt=0;
        for(int i=1;i<=n;i++){
            flag = 1;
            if(!check[i]){
                dfs(i, 0);
                if(flag)cnt++;
            }
        }

        cout << "Case " << t << ": ";
        if(cnt==0){
            cout << "No trees.\n";
        }
        else if(cnt==1){
            cout << "There is one tree.\n";
        }
        else{
            cout << "A forest of " << cnt << " trees.\n";
        }
    }
    

    return 0;
}