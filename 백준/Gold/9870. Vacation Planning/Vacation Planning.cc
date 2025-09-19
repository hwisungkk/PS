#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;

    cin >> n >> m >> t >> k; //n은 노드 개수, m은 연결, t는 허브, k는 쿼리 개수

    vector<vector<ll>> graph(n+1, vector<ll>(n+1, 1e9));
    
    for(int i=1;i<=n;i++)graph[i][i]=0;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        graph[a][b]=min(graph[a][b], c);
        
    }

    for(int i=1;i<=n;i++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                graph[x][y]=min(graph[x][y], graph[x][i]+graph[i][y]);
            }
        }
    }

    vector<vector<ll>> ansv(n+1, vector<ll>(n+1, 1e9));
    for(int i=1;i<=t;i++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                ansv[x][y]=min(ansv[x][y], graph[x][i]+graph[i][y]);
            }
        }
    }
    int cnt=0;

    for(int i=0;i<k;i++){
        cin >> a >> b;
        if(ansv[a][b]<1e9){
            cnt++;
            ans+=ansv[a][b];
        }
    }
    cout << cnt << '\n' << ans;

    return 0;
}