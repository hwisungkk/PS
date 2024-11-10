#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<map>
#include <algorithm>
#include<math.h>
using namespace std;
int ar[60][60]={0};
int count;
void bfs(int n, int m){
    int dx[4]={0, 0, 1, -1};
    int dy[4]={1, -1, 0, 0};
    if(ar[n][m]==1){
        ar[n][m]=0;
        for(int i=0;i<4;i++){
            bfs(n+dx[i], m+dy[i]);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c=0, total=0;
    char ch;
    int ma = -1000;
    int n, m, z=1;
    int dp[10000]={0};
    vector <int> v1;
    vector <int> v2;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=1;j<=a;j++){
            for(int k=1;k<=b;k++){
                ar[j][k]=0;
            }
        }
        cin >> a >> b >> c;
        for(int j=0;j<c;j++){
            cin >> m >> z;
            ar[m+1][z+1]=1;
        }
        for(int j=1;j<=a;j++){
            for(int k=1;k<=b;k++){
                if(ar[j][k]==1){
                    bfs(j, k);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}