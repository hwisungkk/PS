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
int a, b, c;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ar[102][102] = {0};
int check[102][102] = {0};
queue <pair<int, int>> q;
void bfs(int n, int m){
    pair <int, int> p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ar[p.first+dx[i]][p.second+dy[i]]==0 && check[p.first+dx[i]][p.second+dy[i]]==1){
                check[p.first+dx[i]][p.second+dy[i]]=2;
                q.push({p.first+dx[i],p.second+dy[i]});
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int t;
    string s1, s2;

    cin >> a >> b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cin >> ar[i][j];
            if(ar[i][j]==0)check[i][j]=1;
        }
    }
    int count = 0;
    while(1){
        int ve = 0;
        q.push({1,1});
        check[1][1]=2;
        bfs(1,1);
        
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                int remove = 0;
                if(ar[i][j]==1){
                    ve++;
                    for(int k=0;k<4;k++){
                        if(check[i+dx[k]][j+dy[k]]==2){
                            remove++;
                        }
                    }
                    if(remove>=2)ar[i][j]=0;
                }
            }
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(ar[i][j]==0)check[i][j]=1;
                else check[i][j]=0;
            }
        }
        if(ve==0)break;
        count ++;
    }
    cout << count;
    return 0;
}
