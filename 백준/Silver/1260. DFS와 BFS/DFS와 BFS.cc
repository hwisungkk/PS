#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int ar[1001][1001] = {0};
int ar2[1001][1001] = {0};
int count;
queue <int> q;
int check[1001]={0};
int check2[1001]={0};
void bfs(int n, int m)
{
    int qe;
    for (int i = m; i < 1001; i++){
        if (ar2[n][i] == 1 && check2[i]==0){
            q.push(i);
            check2[i]=1;
            ar2[n][i] = 0;
            ar2[i][n] = 0;
        }
    }
    while(!q.empty()){
        qe = q.front();
        cout << qe << " ";
        q.pop();
        bfs(qe,1);
    }
}
void dfs(int n, int m)
{
    cout << n << " ";
    check[n]=1;
    for (int i = m; i < 1001; i++){
        if (ar[n][i] == 1 && check[i]==0){
            ar[n][i] = 0;
            ar[i][n] = 0;
            dfs(i, 1);
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c = 0, total = 0;
    char ch;
    int ma = -1000;
    int n, m, z = 1;
    int dp[10000] = {0};
    vector<int> v1;
    vector<int> v2;
    string s;
    cin >> a >> b >> c;
    for (int i = 0; i < b; i++)
    {
        cin >> n >> m;
        ar[n][m] = 1;
        ar[m][n] = 1;
        ar2[n][m] = 1;
        ar2[m][n] = 1;
    }
    dfs(c, 1);
    cout << '\n';
    q.push(c);
    bfs(c,1);
    return 0;
}