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
int ar[102][102]={0};
int check[102]={0};
long long mi = 1e16;
int total=0;
int n, m, k;
void dfs(int p, int q){
    for(int i=1;i<=n;i++){
        if(!check[i] && ar[q][i]==1){
            ar[p][i]=1;
            check[i]=1;
            dfs(p, i);
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b, c;

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    check[1]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            check[j]=0;
        }
        dfs(i, i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ar[i][j] << ' ';
        }cout << '\n';
    }
    return 0;
}