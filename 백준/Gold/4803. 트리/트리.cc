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
        vector<vector<int>> parent(n+1, vector<int>(2, 0));
        vector<int> high(n+1, 1);
        for(int i=1;i<=n;i++){
            parent[i][0]=i;
        }
        function <int(int)> find = [&](int v){
            if(v==parent[v][0]) return v;
            return parent[v][0] = find(parent[v][0]);
        };
        function <void(int, int)> uni = [&](int a, int b){
            int u = find(a);
            int v = find(b);
            if(u==v){
                parent[u][1]=1;
                return; // 트리가 아니라는 거~
            }
            if(high[u]<high[v]) swap(u,v);

            parent[v][0]=u;
            if(high[u]==high[v])high[u]++;

        };
        for(int i=0;i<m;i++){
            cin >> a >> b;
            uni(a,b);
        }
        vector<int> check(n+1, 0);
        for(int i=1;i<=n;i++){
            if(find(i)!=parent[i][0]){
                parent[i][0]=find(i);
            }
            if(!parent[parent[i][0]][1]){
                check[parent[i][0]]++;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(check[i]>0)cnt++;
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