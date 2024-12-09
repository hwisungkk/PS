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
        cin >> n;
        vector <int> v(n+1);
        for(int i=0;i<n;i++){
            cin >> k;
            v[k]++;
        }
        int count1 = 0;
        int count2=0;
        for(int i=1;i<=n;i++){
            if(v[i]==1){
                count1++;
            }
            if(v[i]>=2){
                count2++;
            }
        }
        int total=0;
        if(count1%2==0){
            total += count1;
        }
        else{
            total = total + (count1 + 1);
        }
        total += count2;
        cout << total << '\n';
    }
 
   
    return 0;
}