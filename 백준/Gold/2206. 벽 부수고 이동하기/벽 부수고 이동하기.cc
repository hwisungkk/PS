#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int ar[1002][1002]={0};
int ar_bfs[2][1002][1002]={0};
int check[2][1002][1002]={0};
queue<pair<int, int>> q;
int idx = 0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int mi = 1e9;
void bfs(int x, int y){
    copy(&ar[0][0], &ar[0][0]+1004004, &ar_bfs[idx][0][0]);
    q.push({x,y});
    check[idx][x][y]=1;
    while(!q.empty()){
        pair <int, int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ar_bfs[idx][p.first+dx[i]][p.second+dy[i]]==1 && check[idx][p.first+dx[i]][p.second+dy[i]]==0){
                ar_bfs[idx][p.first+dx[i]][p.second+dy[i]] = ar_bfs[idx][p.first][p.second]+1;
                check[idx][p.first+dx[i]][p.second+dy[i]]= 1;
                q.push({p.first+dx[i], p.second+dy[i]});
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int n, m, k;
    int t;
    string s;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='1')ar[i][j]=-2;
            else ar[i][j]=1;
        }
    }
    bfs(1,1);
    idx++;
    //길이 뚫렸는지 확인.
    if(ar_bfs[0][n][m]!=1){
        mi = ar_bfs[0][n][m];
    }
    bfs(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]==-2){
                for(int ii=0;ii<4;ii++){
                    for(int jj=0;jj<4;jj++){
                        if(ii!=jj && check[0][i+dx[ii]][j+dy[ii]] && check[1][i+dx[jj]][j+dy[jj]]){
                            mi = min(mi, (ar_bfs[0][i+dx[ii]][j+dy[ii]] + ar_bfs[1][i+dx[jj]][j+dy[jj]] + 1));
                        }
                    }
                }
            }
        }
    }
    if(n==1 && m==1)mi=1; //사이드케이스
    if(mi==1e9)mi=-1; // 이건 길이 없는거
    cout << mi;
    return 0;
}
