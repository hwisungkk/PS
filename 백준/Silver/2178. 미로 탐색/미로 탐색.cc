#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int max = 10001;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ar[102][102] = {0};
int n, m;
queue <pair<int,int>> q;
void bfs(int x, int y){
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(ar[x+dx[i]][y+dy[i]]==1){
                ar[x+dx[i]][y+dy[i]] = ar[x][y]+1;
                q.push({x+dx[i], y+dy[i]});
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long block = 0;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=m;j++){
            ar[i][j]=s[j-1]-48;
        }
    }
    q.push({1,1});
    bfs(1,1);
    cout << ar[n][m];

    return 0;
}