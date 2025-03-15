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
    cin >> t;

    bool flag;

    while(t-->0){
        flag = 1;
        cin >> n >> m;
        vector<int> color(n+1, 0);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<m;i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        function <void(int, int)> dfs=[&](int k, int ch){
            color[k]=ch;
            for(int i=0;i<graph[k].size();i++){
                if(color[graph[k][i]]==0){
                    dfs(graph[k][i], ch*-1);
                }
                else if(color[graph[k][i]]==ch){
                    flag=0;
                    return;
                }
            }
        };
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                dfs(i, 1);    
            }
        }

        if(flag){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    
    

    return 0;
}