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
    vector<int> parent(n+1, 0);
    vector<int> high(n+1, 1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    function <int(int)> find=[&](int a){
        if(a==parent[a])return a;
        else return parent[a] = find(parent[a]);
    };
    function <void(int, int)> uni=[&](int a, int b){
        int u = find(a);
        int v = find(b);
        if(high[u]>high[v])swap(u,v);
        if(u!=v){
            parent[u]=v;
        }
        if(high[u]==high[v])high[u]++;
    };
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        if(a==0){
            uni(b,c);
        }
        if(a==1){
            if(find(b)==find(c)){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }

    return 0;
}