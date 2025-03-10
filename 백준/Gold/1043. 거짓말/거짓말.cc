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
    int n, m, k, t;
    int o_1, o_2;
    cin >> n >> m; //사람, 파티

    vector<int> parent(n+1);
    vector<int> high(n+1, 1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    function <int(int)> find = [&](int n){
        if(n==parent[n])return n;
        return parent[n] = find(parent[n]);
    };
    function <void(int, int)> uni = [&](int a, int b){
        int u = find(a);
        int v = find(b);
        if(u==v)return;

        if(high[u]>high[v]){
            swap(u,v);
        }
        parent[u] = v;
        if(high[u]==high[v])high[v]++;
    };
    cin >> a;
    for(int i=0;i<a;i++){ //진실을 아는 사람
        cin >> t;
        uni(0, t);
    }

    vector<vector<int>> party(m);
    vector<bool> check(m, 0);
    for(int i=0;i<m;i++){
        cin >> a;
        for(int j=0;j<a;j++){
            cin >> t;
            party[i].push_back(t);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<party[i].size();j++){
            if(check[i]==0 && find(0)==find(party[i][j])){
                check[i]=1;
                for(int k=0;k<party[i].size();k++)uni(0,party[i][k]);
                i=-1;
                break;
            }
        }
    }
    int total=0;
    for(int i=0;i<m;i++){
        if(check[i]==0)total++;
    }
    cout << total;

    return 0;
}