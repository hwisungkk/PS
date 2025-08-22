#define ll long long
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998244353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> n >> m;
    
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, 0));
    queue<int> q;
    vector<int>cnt(n+1, 0);
    vector<int>chk(n+1, 0);

    vector<int> anss;

    for(int i=0;i<m;i++){
        cin >> t;
        vector<int> v(t);
        for(int j=0;j<t;j++){
            cin >> v[j];
        }
        for(int j=1;j<t;j++){
            if(graph[v[j-1]][v[j]]==0){
                graph[v[j-1]][v[j]]=1; // 루트에서 밑으로 화살표느낌
                cnt[v[j]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!cnt[i]){
            q.push(i);
            chk[i]=1;
            flag=1;
        }
    }
    if(!flag){
        cout<<0<<'\n';
        return 0;
    }
    while(1){
        while(!q.empty()){
            anss.push_back(q.front());
            for(int i=0;i<=n;i++){
                if(graph[q.front()][i]){
                    graph[q.front()][i]=0;
                    cnt[i]--;
                }
            }
            q.pop();
            k++;
            
        }
        if(k==n)break;
        flag=0;
        for(int i=1;i<=n;i++){
            if(!cnt[i]&&!chk[i]){
                q.push(i);
                chk[i]=1;
                flag=1;
            }
        }
        if(!flag){
            cout<<0<<'\n';
            return 0;
        }
    }

    for(int i=0;i<anss.size();i++){
        cout << anss[i] << '\n';
    }
    

    return 0;
}