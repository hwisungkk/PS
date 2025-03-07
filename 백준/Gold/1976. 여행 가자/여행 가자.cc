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
    cin >> n >> m;

    vector<int> parent(n+1);
    vector<int> high(n+1, 1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    function <int(int)> find = [&](int n){
        if(n==parent[n])return n;
        return parent[n] = find(parent[n]);
    };
    function <void(int, int)> uni = [&](int a, int b){
        int u = find(a);
        int v = find(b);

        if(high[u] > high[v])swap(u,v);
        if(u!=v){
            parent[u] = v;
        }
        if(high[u]==high[v])high[u]++;
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a;
            if(a==1){
                uni(i,j);
            }
        }
    }
    cin >> t;
    int chk = 1;
    int ans = find(t);
    for(int i=1;i<m;i++){
        cin >> t;
        if(ans!=find(t)){
            chk = 0;
        }
    }
    if(chk)cout << "YES";
    else cout << "NO";

    return 0;
}