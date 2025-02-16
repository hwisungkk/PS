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
    char c1, c2, c3;

    cin >> n;
    vector<vector<int>> v(n+1);
    vector<int> ans(n+1, 0);
    vector<int> check(n+1, 0);

    string s1="", s2="", s3="";
    
    for(int i=0;i<n;i++){
        cin >> c1 >> c2 >> c3;
        v[c1-64].push_back(c2-64);
        v[c1-64].push_back(c3-64);
    }

    function <void(int)> dfs = [&](int n){
        s1 += char(n+64);
        check[n]=1;
        for(int i=0;i<v[n].size();i++){
            if(i==1)s2+=char(n+64);
            if(v[n][i]!='.'-64 && check[v[n][i]]==0){
                ans[v[n][i]] = n;
                dfs(v[n][i]);
            }
        }
        s3 += char(n+64);
    };
    dfs(1);

    cout << s1 << '\n' << s2 << '\n' << s3 << '\n';

    return 0;
}