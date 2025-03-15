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
    vector<vector<int>> graph(n+1);
    vector<int> left;
    vector<int> right;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> color(n+1,0);
    function <void(int, int)> dfs = [&](int k, int ch){
        color[k]=ch;
        if(ch==1)left.push_back(k);
        else right.push_back(k);
        for(int i=0;i<graph[k].size();i++){
            if(color[graph[k][i]]==0){
                dfs(graph[k][i], ch*-1);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs(i, 1);
        }
    }

    if(left.size()%2==1 && right.size()%2==1){ //둘 다 홀 수
        bool flag=1;
        for(int i=0;i<left.size();i++){
            if(graph[left[i]].size()!=right.size()){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << n/2-1;
        }
        else cout << n/2;
    }
    else{
        cout << n/2;
    }
    

    return 0;
}