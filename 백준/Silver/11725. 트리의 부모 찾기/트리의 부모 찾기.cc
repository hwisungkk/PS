#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] ={-1,1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;

    cin >> n;
    vector<vector<int>> v(n+1);
    vector<int> ans(n+1, 0);
    vector<int> check(n+1, 0);
    
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    function <void(int)> dfs = [&](int n){
        check[n]=1;
        for(int i=0;i<v[n].size();i++){
            if(check[v[n][i]]==0){
                ans[v[n][i]] = n;
                dfs(v[n][i]);
            }
        }

    };
    dfs(1);

    for(int i=2;i<=n;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}