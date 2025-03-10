#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    cin >> n;
    vector<vector<long long>> length(100001, vector<long long>(2,0));
    for(int i=0;i<n;i++){
        cin >> m;
        length[m][0]++;
    }
    long long ans=0;
    long long x=0, y=0;
    for(int i=100000;i>=2;i--){
        if(length[i][0]+length[i][1]>=2){
            length[i][1]-=2;
            if(length[i][1]<0){
                length[i][0] += length[i][1];
                length[i][1]=0;
            }
            if(x==0)x=i;
            else if(y==0)y=i;
            i++;
        }
        else if(length[i][0]==1){
            length[i-1][1]++;
        }
        if(x!=0 && y!=0){
            ans += x*y;
            x=y=0;
        }
    }
    cout << ans;
    
    return 0;
}