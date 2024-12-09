#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main()
{
    int n, m, k;
    long long a, b, c, count=0;
    int total=0;
    string s;
    int t;
 
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<>());
        total = 0;
        for(int i=0;i<n;i++){
            total+=v[i];
            if(total>k){
                total-=v[i];
                break;
            }
        }
        cout << k - total << '\n';
    }
 
   
    return 0;
}