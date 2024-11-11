#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int count1=0;
int count2=0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c = 0, total = 0;
    char ch;
    int ma = -1000;
    int count =0;
    int n, m, z = 1;
    char ar[605][605] = {0};
    int check[1001];
    vector<int> v1;
    string s;
    pair <int, int> p;
    cin >> n >> m;
    queue <pair<int, int>> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
            if(ar[i][j]=='I')q.push({i,j});
        }
    }
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int j=0;j<4;j++){
            if(ar[p.first+dx[j]][p.second+dy[j]]=='P' || ar[p.first+dx[j]][p.second+dy[j]]=='O'){
                if(ar[p.first+dx[j]][p.second+dy[j]]=='P')
                    count++;
                ar[p.first+dx[j]][p.second+dy[j]] = 'G';
                q.push({p.first+dx[j], p.second+dy[j]});
            }
        }
    }
    if(count==0)cout<<"TT";
    else cout << count;
    return 0;
}