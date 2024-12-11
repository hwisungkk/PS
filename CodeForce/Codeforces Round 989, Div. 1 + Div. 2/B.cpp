#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int n, m, k;
    long long a, b, c, count=0;
    int total=0;
    string s;
    vector <pair<pair<string, int>, int>> v;
    int t;
 
    cin >> t;
 
    while(t--){
        cin >> n >> m >> k;
        cin >> s;
        count =0;
        total=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')count++;
            else count =0;
 
            if(count>=m){
                int j = i;
                for(i;i<j+k;i++){
                    
                }
                i--;
                total++;
                count = 0;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout << s[i];
        // }cout << '\n';
        cout << total << '\n';
    }
 
   
    return 0;
}