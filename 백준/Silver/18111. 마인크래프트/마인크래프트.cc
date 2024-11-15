#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long block = 0;
    int n, m;
    int ar[501][501]={0};
    cin >> n >> m >> block;
    long long total_block=block;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
            total_block+=ar[i][j];
        }
    }
    a = (int)total_block/(n*m);

    int min=1000000000;
    int floor=-1;
    for(int k = a;k>=0;k--){
        int t=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ar[i][j]>k){
                    t+=(ar[i][j]-k)*2;
                }
                else{
                    t+=k-ar[i][j];
                }
            }
        }
        if(min>t){
            min=t;
            floor=k;
        }
    }
    cout << min << ' ' << floor;
    return 0;
}