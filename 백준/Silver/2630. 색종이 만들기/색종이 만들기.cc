#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int ar[130][130]={0};
int count1=0;
int count2=0;
void ta(int n, int m, int k){
    int check=0;
    for(int i=n;i<n+k;i++){
        for(int j=m;j<m+k;j++){
            if(ar[n][m]!=ar[i][j]){
                check=1;
                break;
            }
        }
    }
    if(check){//1 3 2
        ta(n,m,k/2); 
        ta(n,m+k/2,k/2); 
        ta(n+k/2,m,k/2); 
        ta(n+k/2,m+k/2,k/2); 
    }
    else{
        if(ar[n][m]) count2++;
        else count1++;
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
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    ta(1,1,n);
    cout << count1 << '\n';
    cout << count2;
    return 0;
}