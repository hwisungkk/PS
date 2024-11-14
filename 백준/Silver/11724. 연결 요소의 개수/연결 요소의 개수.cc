#include <iostream>
#include<vector>
#include<set>
using namespace std;
int ar[1001][1001]={0};
int check[1001]={0};
int count=0;
void DFS(int n, int m){
    for(int j=1;j<=n;j++){
        if(ar[m][j]==1 && check[j]==0){
            check[j]=1;
            DFS(n, j);
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int ma = -1;
    int a, b;
    while(m--){
        cin >> a >> b;
        ar[a][b]=1;
        ar[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            count++;
            DFS(n,i);
        }
    }
    cout << count;


    return 0;
}