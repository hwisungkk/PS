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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    char c1, c2, c3;

    cin >> n >> m >> t;
    vector<vector<int>> v(n+1);
    vector<int> ans(n+1,0);
    vector<int> check(n+1,0);

    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end());
    }
    int cnt=1;
    function <void(int)> dfs = [&](int n){
        check[n]=1;
        ans[n]=cnt;
        for(int i=0;i<v[n].size();i++){
            if(check[v[n][i]]==0){
                cnt++;
                dfs(v[n][i]);
            }
        }
        
    };
    dfs(t);



    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}