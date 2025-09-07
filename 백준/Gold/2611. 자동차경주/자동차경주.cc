#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000'007;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> n >> m;
    vector<int> v(n+1, 0);
    v[1]=0;
    vector<int> cnt(n+1, 0);
    vector<int> chk(n+1, 0);

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        cnt[b]++;
        graph[a][b]=c;
    }

    queue<int> q;
    q.push(1);

    vector<string> vs(n+1, "");

    while(!q.empty()){
        int p=q.front();
        q.pop();
        chk[p]=1;
        for(int i=1;i<=n;i++){
            if(graph[p][i]!=0){
                cnt[i]--;
                if(v[i]<v[p]+graph[p][i]){
                    v[i]=v[p]+graph[p][i];
                    vs[i]="";
                    vs[i]+=vs[p];
                    vs[i]+=to_string(p);
                    vs[i]+=" ";
                }
                if(cnt[i]==0 && chk[i]==0)q.push(i);
            }
        }
    }
    cout << v[1] << '\n';
    vs[1]+="1";
    cout << vs[1] << '\n';

    return 0;
}