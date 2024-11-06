#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int k=1, a, b;
    int x1, x2, y1, y2;
    int check = 0;
    int arr[2000];
    string s;
    char ch;
    int max = -1000000000;
    int ar[1030][1030] = {0};
    int nu[1030][1030] = {0};
    int nu2[1030][1030] = {0};
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            nu[i][j] = nu[i][j-1] + ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            nu2[i][j] = nu2[i-1][j] + nu[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << nu2[x2][y2] - nu2[x1-1][y2] - nu2[x2][y1-1] + nu2[x1-1][y1-1] << '\n';
    }
    return 0;
}