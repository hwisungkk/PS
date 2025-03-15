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
        vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
        vector<bool> check(n+1, 0);
        for(int i=0;i<m;i++){
            cin >> a >> b;
            graph[a][b]=1;
            graph[b][a]=1;
        }
        bool flag = 1;
        function <void(int)> dfs=[&](int k){
            check[k]=1;
            for(int i=1;i<n+1;i++){
                if(graph[k][i]==1 && !check[i]){
                    graph[i][k]=0;
                    dfs(i);
                }
                else if(graph[k][i]==1)flag=0;
            }
        };
        int cnt=0;
        for(int i=1;i<=n;i++){
            flag = 1;
            if(!check[i]){
                dfs(i);
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