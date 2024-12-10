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
long long mi = 1e16;
int total=0;
int check[50][50]={0};
int n;
void dfs(int q){
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << check[i][j] << ' ';
        //     }cout<<'\n';
        // }cout << '\n';
    if(q==n){
        total++;
        return;
    }
    for(int i=0;i<n;i++){
        if(check[q][i]==0){
            for(int j=0;j<n;j++){ //가로
                if(check[q][j]==0)check[q][j]=q+1;
            }
            for(int j=0;j<n;j++){ //세로
                if(check[j][i]==0)check[j][i]=q+1;
            }
            for(int j=0;j<n;j++){ //오른쪽아래 대각
                if(check[q+j][i+j]==0)check[q+j][i+j]=q+1;
            }
            for(int j=0;j<n;j++){ //오른쪽위 대각
                if(check[q+j][i-j]==0)check[q+j][i-j]=q+1;
            }
            check[q][i]=-1;
            dfs(q+1);
            for(int j=0;j<n;j++){ //가로
                if(check[q][j]==q+1)check[q][j]=0;
            }
            for(int j=0;j<n;j++){ //세로
                if(check[j][i]==q+1)check[j][i]=0;
            }
            for(int j=0;j<n;j++){ //오른쪽아래 대각
                if(check[q+j][i+j]==q+1)check[q+j][i+j]=0;
            }
            for(int j=0;j<n;j++){ //오른쪽위 대각
                if(check[q+j][i-j]==q+1)check[q+j][i-j]=0;
            }
            check[q][i]=0;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int m, k;
    long long a, b, c;

    cin >> n;
    dfs(0);
    cout << total;
    return 0;
}