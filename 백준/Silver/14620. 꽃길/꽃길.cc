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
int mi = 1e9;
int flower[13][13]={0};
int check[13][13]={0};
int total;
void dfs(int n, int t){
    if(n==3){
        if(mi > total)mi=total;
        return;
    }
    for(int i=2;i<=t-1;i++){
        for(int j=2;j<=t-1;j++){
            if(check[i][j]==0){
                total += flower[i][j];
                check[i][j]++;check[i+1][j]++;check[i+2][j]++;check[i-2][j]++;check[i-1][j]++;check[i][j-1]++;check[i][j-2]++;check[i][j+1]++;check[i][j+2]++;check[i+1][j+1]++;check[i-1][j+1]++;check[i+1][j-1]++;check[i-1][j-1]++;
                dfs(n+1, t);
                check[i][j]--;check[i+1][j]--;check[i+2][j]--;check[i-2][j]--;check[i-1][j]--;check[i][j-1]--;check[i][j-2]--;check[i][j+1]--;check[i][j+2]--;check[i+1][j+1]--;check[i-1][j+1]--;check[i+1][j-1]--;check[i-1][j-1]--;
                total -= flower[i][j];
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    int t = 0;
    cin >> t;
    vector <vector<int>> ar(t+2, vector<int>(t+2));
    for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=2;i<=t-1;i++){
        for(int j=2;j<=t-1;j++){
            flower[i][j] = ar[i][j] + ar[i-1][j] + ar[i+1][j] + ar[i][j+1] + ar[i][j-1];
        }
    }
    dfs(0, t);
    cout << mi;
    return 0;
}