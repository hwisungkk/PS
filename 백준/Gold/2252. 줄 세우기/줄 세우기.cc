#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int k, n;
vector <vector<int>> ar(32001);
vector <set<int>> degree(32001);
vector <int> check(32001, 0);
void dfs(int z){
    if(degree[z].size()==0 && check[z]==0){
        check[z]=1;
        cout << z << ' ';
        for(int i=0;i<ar[z].size();i++){
            degree[ar[z][i]].erase(z);
        }
        for(int i=0;i<ar[z].size();i++){
            dfs(ar[z][i]);
        }
    }
    else{
        return;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        ar[a].push_back(b);
        degree[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    // for(int i=1;i<=n;i++){
    //     cout << ar[i].size() << ' ' << degree[i].size() << '\n';
    // }
    return 0;
}
//8 2 9 1 4 6 7 10