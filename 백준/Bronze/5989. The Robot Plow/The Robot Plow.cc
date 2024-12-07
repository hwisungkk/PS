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
int ar[1002][1002]={0};
int check[102]={0};
long long mi = 1e16;
int total=0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    long long a, b, c;

    cin >> n >> m >> k;
    while(k--){
        int d;
        cin >> a >> b >> c >> d;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                ar[i][j]=1;
            }
        }
    }
    int total=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]==1)total++;
        }
    }
    cout << total;

    
    return 0;
}