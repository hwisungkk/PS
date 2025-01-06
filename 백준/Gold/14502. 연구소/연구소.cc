#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m;
int ar[10][10]={0};
vector<pair<int, int>> blank;
queue <pair<int, int>> virus;
queue <pair<int, int>> q;
int back_check[64]={0};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int ma=-1;
void bfs(){
    int check[10][10]={0};
    for(int i=0;i<10;i++)check[i][0]=1;
    for(int i=0;i<10;i++)check[0][i]=1;
    for(int i=0;i<10;i++)check[n+1][i]=1;
    for(int i=0;i<10;i++)check[i][m+1]=1;
    int count=0;
    while(!q.empty()){
        pair<int,int> p;
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ar[p.first+dx[i]][p.second+dy[i]]==0 && check[p.first+dx[i]][p.second+dy[i]]==0){
                check[p.first+dx[i]][p.second+dy[i]]=1;
                q.push({p.first+dx[i], p.second+dy[i]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]==0 && check[i][j]==0){
                count++;
            }
        }
    }
    ma = max(ma, count);
}
void back(int k){
    if(k==3){
        q=virus;
        bfs();
        return;
    }
    for(int i=0;i<blank.size();i++){
        if(back_check[i]==0){
            back_check[i]=1;
            ar[blank[i].first][blank[i].second]=1;
            back(k+1);
            back_check[i]=0;
            ar[blank[i].first][blank[i].second]=0;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int t;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
            if(ar[i][j]==0){
                blank.push_back({i,j});
            }
            if(ar[i][j]==2){
                virus.push({i,j});
            }
        }
    }
    back(0);
    cout << ma;

    return 0;
}
