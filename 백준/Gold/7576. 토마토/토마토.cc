#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int k=1, a, count=0;
    int check = 0;
    int ar[1005][1005] = {0};
    queue <pair<int, int>> q;
    pair <int,int> p;
    cin >> n >> m;
    for(int i=0;i<=1004;i++){
        for(int j=0;j<=1004;j++){
            ar[i][j]= -1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
            if(ar[i][j]==1){
                q.push({i,j});
            }
        }
    }
    count = 1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ar[p.first+dx[i]][p.second+dy[i]]==0){
                ar[p.first+dx[i]][p.second+dy[i]]=ar[p.first][p.second]+1;
                count = ar[p.first+dx[i]][p.second+dy[i]];
                q.push({p.first+dx[i], p.second+dy[i]});
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]==0){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << count-1;

    return 0;
}