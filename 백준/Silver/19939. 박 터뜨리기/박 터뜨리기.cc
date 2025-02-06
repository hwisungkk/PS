#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;

    cin >> n >> m;
    int mi=0, ma=0;
    if(m*(m+1)/2 > n){
        cout << "-1";
    }
    else{
        int cnt=0;
        for(int i=m;i>0;i--){
            while(n>=((i-1)*(i)/2)){
                n-=i;
                cnt++;
            }
            n+=i;
            cnt--;
            if(i==m)mi=cnt;
            if(i==1)ma=cnt;
        }
        cout << ma - mi;
    }
    return 0;
}