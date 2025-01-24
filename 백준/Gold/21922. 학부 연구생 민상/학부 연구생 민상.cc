#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    int a, b, c, d;
    cin >> n >> m;
    int lab[2001][2001];
    bool check[2001][2001][4]={0};
    queue <pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> lab[i][j];
            if(lab[i][j]==9){
                q.push({i,j});
            }
        }
    }
    //dir 0은 오른쪽, 1은 왼쪽, 2는 위쪽, 3은 아래쪽
    int paint = 0;
    pair<int, int> p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            check[p.first][p.second][i]=1;
        }
        for(int i=0;i<4;i++){
            int x = p.first;
            int y = p.second;
            int dir = i;
            while(1){
                if(!(x+dx[dir]>=0 && y+dy[dir]>=0 && x+dx[dir] < n && y+dy[dir]<m))break;
                int cc = lab[x+dx[dir]][y+dy[dir]];

                if(check[x+dx[dir]][y+dy[dir]][dir]==0){
                    check[x+dx[dir]][y+dy[dir]][dir] = 1;
                    x+=dx[dir];
                    y+=dy[dir];
                    if(cc==1){
                        if(dir==0 || dir==1)break;
                        else continue;
                    }
                    else if(cc==2){
                        if(dir==2 || dir==3)break;
                        else continue;
                    }
                    else if(cc==3){
                        if(dir==0)dir=2;
                        else if(dir==1)dir=3;
                        else if(dir==2)dir=0;
                        else if(dir==3)dir=1;
                    }
                    else if(cc==4){
                        if(dir==0)dir=3;
                        else if(dir==1)dir=2;
                        else if(dir==2)dir=1;
                        else if(dir==3)dir=0;
                    }
                    else continue;
                }
                else break;
            }
        }
    }
    int xz=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            xz=0;
            for(int k=0;k<4;k++){
                if(check[i][j][k]!=0)xz++;
            }//cout << xz << ' ';
            if(xz!=0)cnt++;
        }//cout << '\n';
    }
    cout << cnt;

    return 0;
}