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

    cin >> n >> m;

    vector<vector<int>> v(n+1, vector<int>(n+1, 1e9));

    for(int i=1;i<=n;i++)v[i][i]=0;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        v[a][b]=min(v[a][b], (int)c);
    }

    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            if(v[i][x]==1e9)continue;
            for(int j=1;j<=n;j++){
                if(v[x][j]==1e9)continue;
                if(v[i][j]>v[i][x]+v[x][j]){
                    v[i][j]=v[i][x]+v[x][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        string sp="";
        for(int j=1;j<=n;j++){
            if(v[i][j]==1e9)v[i][j]=0;
            cout << sp << v[i][j];
            sp=" ";
        }cout << '\n';
    }
    
    return 0;
}