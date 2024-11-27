#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int ma=-1;
char ch[202][202];
int check[202][202]={0};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector <char> v;
void dfs(int n, int m){
    check[n][m]=1;
    v.push_back(ch[n][m]);
    al++;
    if(ma<al){
        ma=al;
    }
    for(int i=0;i<4;i++){
        if(check[n+dx[i]][m+dy[i]]==0 && 
        (find(v.begin(), v.end(), ch[n+dx[i]][m+dy[i]]))==v.end()){
            //cout << "n: " << n+dx[i] << "m: " << m+dy[i] << '\n';
            dfs(n+dx[i], m+dy[i]);
        }
    }
    check[n][m]=0;
    v.pop_back();
    al--;
}  

int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    string s1, s2;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ch[i][j];
        }
    }
    v.push_back('\0');
    dfs(1,1);
    cout << ma;

    return 0;
}