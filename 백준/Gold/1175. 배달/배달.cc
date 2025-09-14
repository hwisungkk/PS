#define ll long long
#include <bits/stdc++.h>
using namespace std;
bool vis[50][50][4][2][2];
struct INFO{
    int x;
    int y;
    int cnt;
    int dir;
    bool c1_v;
    bool c2_v;
};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> n >> m;
    vector<string> vs(n);
    for(int i=0;i<n;i++){
        cin >> vs[i];
    }

    pair<int,int> start;
    pair<int,int> c1;
    pair<int,int> c2;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vs[i][j]=='S'){
                start.first=i;
                start.second=j;
            }
            else if(vs[i][j]=='C' && !flag){
                flag=1;
                c1.first=i;
                c1.second=j;
            }
            else if(vs[i][j]=='C'){
                c2.first=i;
                c2.second=j;
            }
        }
    }
    flag=0;
    //cout << start.first << ' ' << start.second<<'\n'<<c1.first<<' ' <<c1.second << '\n' << c2.first << ' ' << c2.second << '\n';

    queue<INFO> q;
    q.push({start.first, start.second, 0, -1, 0, 0});

    while(!q.empty()){
        INFO in;
        in.x = q.front().x;
        in.y = q.front().y;
        in.cnt = q.front().cnt;
        in.dir = q.front().dir;
        in.c1_v = q.front().c1_v;
        in.c2_v = q.front().c2_v;
        q.pop();


        if(in.x==c1.first&&in.y==c1.second)in.c1_v=1;
        if(in.x==c2.first&&in.y==c2.second)in.c2_v=1;
        //cout << in.x << ' ' << in.y << ' ' << in.c1_v << ' ' << in.c2_v << '\n';
        if(in.c1_v&&in.c2_v){
            flag=1;
            cout<<in.cnt;
            break;
        }

        for(int i=0;i<4;i++){
            if(in.dir==i)continue;
            int xx=in.x+dx[i];
            int yy=in.y+dy[i];


            if(xx>=0&&xx<n&&yy>=0&&yy<m && vs[xx][yy]!='#' && vis[xx][yy][i][in.c1_v][in.c2_v]==0){
                vis[xx][yy][i][in.c1_v][in.c2_v]=1;
                q.push({xx, yy, in.cnt+1, i, in.c1_v, in.c2_v});
            }
        }
    }
    if(!flag)cout<<"-1";


    return 0;
}