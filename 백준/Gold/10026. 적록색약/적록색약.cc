#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n = 0;
char ar[105][105];
int check[105][105];
queue <pair<int, int>> q;
int dx[4]={0,0,1,-1};
int dy[4] ={1,-1,0,0};
void bfs(){
    while(!q.empty()){
        pair <int, int> p;
        p = q.front();
        q.pop();
        //cout << p.first << " " << p.second << '\n';
        for(int i=0;i<4;i++){
            if(!check[p.first+dx[i]][p.second+dy[i]] && ar[p.first+dx[i]][p.second+dy[i]]==ar[p.first][p.second]){
                q.push({p.first+dx[i], p.second+dy[i]});
                check[p.first+dx[i]][p.second+dy[i]]=1;
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
    int m;
    cin >> n;
    char ch;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ch;
            ar[i][j] = ch;
        }
    }
    int count1=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!check[i][j]){
                q.push({i,j});
                check[1][1]=1;
                bfs();
                count1++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            check[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]=='R')
                ar[i][j]='G';
        }
    }
    int count2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!check[i][j]){
                q.push({i,j});
                check[1][1]=1;
                bfs();
                count2++;
            }
        }
    }
    cout << count1 << " " << count2;
    return 0;
}