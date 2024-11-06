/*https://codeforces.com/contest/2032/problem/A*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total=0;
    long long count=0;
    int ma = -1000;
    long long n, m, k=-1;
    int dp[101]={0};
    vector <vector <int>>kc;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        total=0;
        for(int j=0;j<2*m;j++){
            cin >> c;
            total+=c;
        }
        if(total%2==0)a=0;
        else a=1;
        if(total<=m)b = total;
        else b = 2*m-total;
 
        cout << a << " " << b << "\n";
    }
    
    return 0;
}
//3
//1 1 1 1 1 1